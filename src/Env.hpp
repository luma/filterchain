// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef ENV_H_
#define ENV_H_

#include "common.hpp"

class Env {
 public:
  Env();
  ~Env();

 public:
  inline v8::Isolate* const GetIsolate() { return isolate_; }
  v8::Handle<v8::Context> NewContext();

 private:
  v8::Isolate* const isolate_;
  v8::Handle<v8::ObjectTemplate> globalTemplate_;
};

#endif
