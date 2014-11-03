#include "Env.hpp"


// The callback that is invoked by v8 whenever the JavaScript 'print'
// function is called.  Prints its arguments on stdout separated by
// spaces and ending with a newline.
void PrintMessage(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;

  for (int i = 0; i < args.Length(); i++) {
    v8::HandleScope handle_scope(args.GetIsolate());
    if (first) {
      first = false;
    } else {
      printf(" ");
    }

    v8::String::Utf8Value str(args[i]);
    const char* cstr = ToCString(str);
    printf("%s", cstr);
  }

  printf("\n");
  fflush(stdout);
}

Env::Env(v8::Isolate* isolate)
    : isolate_ {isolate} {

  // Create a stack-allocated handle scope.
  // v8::HandleScope handleScope(isolate_);

  // Create a template for the global object.
  auto globalTemplate = v8::ObjectTemplate::New();

  // // Add global functions/objects
  // // v8::Handle<v8::ObjectTemplate> module = v8::ObjectTemplate::New();
  // // globalTemplate_->Set(v8::String::NewFromUtf8(isolate_, "module"), module);

  globalTemplate->Set(v8::String::NewFromUtf8(isolate_, "echo"),
                    v8::FunctionTemplate::New(isolate_, PrintMessage));

  globalTemplate_ = v8::Persistent<
                        v8::ObjectTemplate,
                          v8::CopyablePersistentTraits<v8::ObjectTemplate>>
                            (isolate_, globalTemplate);
}

Env::~Env() {
  // @todo how do we do cleanup?

  contexts_.clear();
  // isolateScope_ something something
  // globalTemplate_.Dispose();
  // isolate_.Dispose();
}


// Creates a new execution environment containing the built-in
// functions.
//
// Creates a stack-allocated handle scope for the new context.
//
PersistentContext Env::NewContext() {
  // v8::HandleScope handleScope(isolate_);

  v8::Handle<v8::ObjectTemplate> global =
      v8::Local<v8::ObjectTemplate>::New(isolate_, globalTemplate_);

  return PersistentContext(isolate_, v8::Context::New(isolate_, nullptr, global));
  // return v8::Context::New(isolate_, nullptr, globalTemplate_);
  // v8::HandleScope handleScope(isolate_);

  // v8::Handle<v8::Context> context
  //         = v8::Context::New(isolate_, nullptr, globalTemplate_);

  // if ( context.IsEmpty()) {
  //   fprintf(stderr, "Error creating context");
  //   // @todo actually bail out when this happens
  // }

  // contexts_.emplace(context, handleScope);

  // return handleScope.Close(context);
}

void Env::DeleteContext(v8::Handle<v8::Context> context) {
  // contexts_.erase(context);
}
/*
Isolate *isolate = Isolate::GetCurrent();
HandleScope scope(isolate);

context = Persistent<v8::Context, CopyablePersistentTraits<v8::Context>>(isolate_, nullptr, globalTemplate_);

Local<External> external = External::New(isolate, reinterpret_cast<void*>(Module));
module = Persistent<External, CopyablePersistentTraits<External>>(isolate, external);


v8::Persistent<v8::External, v8::CopyablePersistentTraits<v8::External>> module; // this is only for binding scripts
PersistentContext context;
std::unordered_map<std::string, v8::Persistent<v8::Script, v8::CopyablePersistentTraits<v8::Script>>> scripts;

v8::Persistent<v8::Script, v8::CopyablePersistentTraits<v8::Script>> Compile(std::string Source);
v8::Persistent<v8::Value, v8::CopyablePersistentTraits<v8::Value>> Execute(v8::Persistent<v8::Script, v8::CopyablePersistentTraits<v8::Script>> Script, std::string Name = "");


*/