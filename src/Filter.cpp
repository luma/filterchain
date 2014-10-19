// © Copyright 2014 TokBox. All Rights Reserved.
#include "Filter.hpp"

Filter::Filter(v8::Handle<v8::Context> context)
    : context_ {context} {
}

Filter::~Filter() {
  // Dispose the persistent handles.  When noone else has any
  // references to the objects stored in the handles they will be
  // automatically reclaimed.
  // @fixme this don't work
  // for (const auto &processor : processors_) {
  //   processor.second.Reset();
  // }
}


v8::Local<v8::String> Filter::LoadSource(const char* fileName) {
  FILE* file = fopen(fileName, "rb");
  if (file == nullptr) {
    // @todo  something sensible
    printf("Could not read filter from %s\n", fileName);
    return v8::String::Empty(GetIsolate());
  }

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* chars = new char[size + 1];
  chars[size] = '\0';

  for (int i = 0; i < size;) {
    int read = static_cast<int>(fread(&chars[i], 1, size - i, file));
    i += read;
  }

  fclose(file);

  v8::Local<v8::String> result =
      v8::String::NewFromUtf8(GetIsolate(), chars, v8::String::kNormalString, size);

  delete[] chars;
  return result;
}

bool Filter::Load(const char* fileName) {
  // assert(object_.IsEmpty());

  v8::Local<v8::String> source = LoadSource(fileName);
  if (source->Length() == 0) {
    return false;
  }

  scriptName_ = v8::String::NewFromUtf8(GetIsolate(), fileName);

  context_->Enter();

  v8::ScriptOrigin origin(scriptName_);

  v8::TryCatch tryCatch;
  auto script = v8::Script::Compile(source, &origin);

  context_->Exit();

  if (script.IsEmpty()) {
    ReportException(&tryCatch);
    return false;
  }


  return Eval(script);
}

bool Filter::Eval(v8::Handle<v8::Script> script) {
  context_->Enter();

  // Create a nested handle scope
  v8::HandleScope localHandleScope(GetIsolate());

  // Enter the execution context before evaluating any code.
  v8::Context::Scope contextScope(context_);

  v8::TryCatch tryCatch;

  v8::Local<v8::Value> result = script->Run();
  if (tryCatch.HasCaught()) {
    ReportException(&tryCatch);
    return false;
  }

  if (!LoadMeta()) {
    return false;
  }

  LoadProcessor("onIncomingPacket");
  LoadProcessor("onOutgoingPacket");

  context_->Exit();

  return true;
}

bool Filter::LoadMeta() {
  v8::Handle<v8::Value> fnValue = context_->Global()->Get(v8::String::NewFromUtf8(GetIsolate(), "meta"));

  // If there is no Process function, or if it is not a function,
  // bail out
  if (!fnValue->IsFunction()) {
    printf("The filter has no  meta function\n");
    return false;
  }

  auto fn = v8::Handle<v8::Function>::Cast(fnValue);

  // Create a handle scope to keep the temporary object references.
  v8::HandleScope localHandleScope(GetIsolate());

  // Create a new local context
  auto context = v8::Local<v8::Context>::New(GetIsolate(), context_);

  // Enter the new execution context before evaluating any code so that
  // all the remaining operations take place there
  v8::Context::Scope contextScope(context);

  // Invoke the process function, giving the global object as 'this'
  // and whatever arguments were passed in
  auto process = v8::Local<v8::Function>::New(GetIsolate(), fn);

  v8::Local<v8::Value> result;

  {
    // Set up an exception handler before calling the handler function
    v8::TryCatch tryCatch;

    result = process->Call(context->Global(), 0, {});

    if (tryCatch.HasCaught()) {
      ReportException(&tryCatch);
      return false;
    }
  }

  v8::Local<v8::Object> meta = result->ToObject();
  v8::Handle<v8::Value> nameValue = meta->Get(v8::String::NewFromUtf8(GetIsolate(), "name"));

  if (!nameValue.IsEmpty()) {
    name_.assign(*v8::String::Utf8Value(nameValue->ToString()));
  }

  return true;
}

bool Filter::LoadProcessor(const char *fnName) {
  // The script compiled and ran correctly.  Now we fetch out the
  // Process function from the global object.
  v8::Handle<v8::Value> fnValue = context_->Global()->Get(v8::String::NewFromUtf8(GetIsolate(), fnName));

  // If there is no Process function, or if it is not a function,
  // bail out
  if (!fnValue->IsFunction()) {
    printf("The %s filter has no  %s function\n", name_.c_str(), fnName);
    return false;
  }

  // It is a function; cast it to a Function and store the
  // function in a Persistent handle, since we also want that
  // to remain after this call returns
  processors_[fnName].Reset(GetIsolate(),
                            v8::Persistent<v8::Function>::Persistent(GetIsolate(),
                                    v8::Handle<v8::Function>::Cast(fnValue)));

  return true;
}

bool Filter::Run(const char *processorName,
                 const int argc,
                 v8::Handle<v8::Value> argv[],
                 v8::Local<v8::Value> &result) {
  auto processor = processors_.find(processorName);

  if (processor == processors_.end()) {
    printf("Processor %s was not found in filter %s", processorName, name_.c_str());
    return false;
  }

  context_->Enter();

  // Create a handle scope to keep the temporary object references.
  v8::HandleScope localHandleScope(GetIsolate());

  // Create a new local context
  auto context = v8::Local<v8::Context>::New(GetIsolate(), context_);

  // Enter the new execution context before evaluating any code so that
  // all the remaining operations take place there
  v8::Context::Scope contextScope(context);

  // Invoke the process function, giving the global object as 'this'
  // and whatever arguments were passed in
  auto process = v8::Local<v8::Function>::New(GetIsolate(), processor->second);

  {
    // Set up an exception handler before calling the handler function
    v8::TryCatch tryCatch;

    result = process->Call(context->Global(), argc, argv);

    context_->Exit();

    if (tryCatch.HasCaught()) {
      ReportException(&tryCatch);
      return false;
    }
  }

  return true;
}

bool Filter::ProcessIncoming(const int argc, v8::Handle<v8::Value> argv[], v8::Local<v8::Value> &result) {
  return Run("onIncomingPacket", argc, argv, result);
}

bool Filter::ProcessOutgoing(const int argc, v8::Handle<v8::Value> argv[], v8::Local<v8::Value> &result) {
  return Run("onOutgoingPacket", argc, argv, result);
}

void Filter::ReportException(v8::TryCatch* tryCatch) {
  ::ReportException(context_->GetIsolate(), tryCatch);
}
