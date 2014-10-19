// © Copyright 2014 TokBox. All Rights Reserved.
#include "FilterChain.hpp"

FilterChain::FilterChain(std::shared_ptr<Env> env) : env_ {env} {
}

FilterChain::~FilterChain() {
  // @todo clean up filters_
  env_.reset();
}

bool FilterChain::Add(const char *path) {
  v8::Handle<v8::Context> context = env_->NewContext();
  // filters_.emplace_back(context);

  // if (!filters_.back().Load(path)) {
  //   printf("✘ Could not load filter from %s\n", path);
  //   return false;
  // }

  return true;
}

bool FilterChain::ProcessIncoming(const int argc, v8::Handle<v8::Value> args[]) {
  // @todo refactor out duplication between ProcessIncoming and ProcessOutgoing
  for (auto &filter : filters_) {
    v8::Local<v8::Value> result;
    if (!filter.ProcessIncoming(argc, args, result)) {
      // @todo handle error and bail?
      return true;
    }

    // @todo do something with result?

    // check if result is false, stop processing if it is
    if (result->IsFalse()) {
      printf("%s Incoming filter chain halted", filter.GetName().c_str());
      return true;
    }
  }

  return false;
}

bool FilterChain::ProcessOutgoing(const int argc, v8::Handle<v8::Value> args[]) {
  // @todo refactor out duplication between ProcessIncoming and ProcessOutgoing
  for (auto &filter : filters_) {
    v8::Local<v8::Value> result;

    if (!filter.ProcessOutgoing(argc, args, result)) {
      // @todo handle error and bail?
      return true;
    }

    // @todo do something with result?

    // check if result is false, stop processing if it is
    if (result->IsFalse()) {
      printf("%s Outgoing filter chain halted", filter.GetName().c_str());
      return true;
    }
  }

  return false;
}