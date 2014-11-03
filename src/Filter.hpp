// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef FILTER_HPP_
#define FILTER_HPP_

#include "common.hpp"

class Filter {
 public:
  explicit Filter(PersistentContext context);
  ~Filter();

 public:
  bool Load(const char* fileName);
  bool ProcessIncoming(const int argc, v8::Handle<v8::Value> args[], v8::Local<v8::Value> &result);
  bool ProcessOutgoing(const int argc, v8::Handle<v8::Value> argv[], v8::Local<v8::Value> &result);

  const std::string GetName() { return name_; }
  PersistentContext GetContext() { return context_; }

 private:
  bool LoadMeta();
  v8::Local<v8::String> LoadSource(const char* fileName);
  void ReportException(v8::TryCatch* tryCatch);
  bool Eval(v8::Handle<v8::Script> script);
  bool LoadProcessor(const char *fnName);
  bool Run(const char *processorName,
            const int argc,
            v8::Handle<v8::Value> argv[],
            v8::Local<v8::Value> &result);

  v8::Handle<v8::Function> GetFunction(const char *fnName);
  // v8::Isolate* const GetIsolate() { return context_->GetIsolate(); }

  v8::Local<v8::Context> GetLocalContext() {
    return v8::Local<v8::Context>::New(v8::Isolate::GetCurrent(), context_);
  }

 private:
  std::string name_ = "Unknown";

  PersistentContext context_;
  v8::Handle<v8::String> scriptName_;

  std::map<const char *, PersistentFunction> processors_;
};


#endif
