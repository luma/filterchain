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

Env::Env() : isolate_ {v8::Isolate::New()} {
  // Make  isolate the active scope
  v8::Isolate::Scope isolateScope(isolate_);

  // Create a stack-allocated handle scope.
  v8::HandleScope handleScope(isolate_);

  // Create a template for the global object.
  globalTemplate_ = v8::ObjectTemplate::New();

  // Add global functions/objects
  // v8::Handle<v8::ObjectTemplate> module = v8::ObjectTemplate::New();
  // globalTemplate_->Set(v8::String::NewFromUtf8(isolate_, "module"), module);

  globalTemplate_->Set(v8::String::NewFromUtf8(isolate_, "echo"),
                    v8::FunctionTemplate::New(isolate_, PrintMessage));
}

Env::~Env() {
  // @todo how do we do cleanup?
  // globalTemplate_.Dispose();
  // isolate_.Dispose();
}

// Creates a new execution environment containing the built-in
// functions.
v8::Handle<v8::Context> Env::NewContext() {
  return v8::Context::New(isolate_, nullptr, globalTemplate_);
}
