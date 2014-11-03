// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef ENV_H_
#define ENV_H_

#include "common.hpp"

class Env {
 public:
  Env(v8::Isolate* isolate);
  ~Env();

 public:
  inline v8::Isolate* const GetIsolate() { return isolate_; }
  PersistentContext NewContext();
  void DeleteContext(v8::Handle<v8::Context> context);

 private:
  v8::Isolate* const isolate_;
  v8::Persistent<v8::ObjectTemplate, v8::CopyablePersistentTraits<v8::ObjectTemplate>> globalTemplate_;

  std::map<v8::Handle<v8::Context>, v8::HandleScope> contexts_;
};


#endif
