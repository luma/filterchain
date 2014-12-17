// © Copyright 2014 TokBox. All Rights Reserved.
#include "FilterChain.hpp"

FilterChain::FilterChain(std::shared_ptr<Env> env) : env_ {env} {
}

FilterChain::~FilterChain() {
  for (auto &filter : filters_) {
    // env_->DeleteContext(filter.GetContext());
  }

  filters_.clear();
  env_.reset();
}

bool FilterChain::Add(const char *path) {
  // v8::Persistent<v8::Context, v8::CopyablePersistentTraits<v8::Context>> context = env_->NewContext();
  // filters_.emplace_back(context);

  Filter filter(env_->NewContext());

  if (!filter.Load(path)) {
    printf("✘ Could not load filter from %s\n", path);
    return false;
  }

  filters_.emplace_back(filter);
  return true;
}

bool FilterChain::ProcessIncoming(const int argc, v8::Handle<v8::Value> args[]) {
  // @todo refactor out duplication between ProcessIncoming and ProcessOutgoing
  for (auto &filter : filters_) {
    if (!filter.ProcessIncoming(argc, args)) {
      printf("\t%s Incoming filter chain halted\n", filter.GetName().c_str());
      return true;
    }
  }

  return false;
}

bool FilterChain::ProcessOutgoing(const int argc, v8::Handle<v8::Value> args[]) {
  // @todo refactor out duplication between ProcessIncoming and ProcessOutgoing
  for (auto &filter : filters_) {
    if (!filter.ProcessOutgoing(argc, args)) {
      printf("\t%s Outgoing filter chain halted\n", filter.GetName().c_str());
      return true;
    }
  }

  return false;
}
