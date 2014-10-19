// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef FILTER_CHAIN_HPP_
#define FILTER_CHAIN_HPP_

#include <deque>

#include "common.hpp"
#include "Env.hpp"
#include "Filter.hpp"

class FilterChain {
 public:
  explicit FilterChain(std::shared_ptr<Env> env);
  ~FilterChain();

 public:
  bool Add(const char *path);
  bool ProcessIncoming(const int argc, v8::Handle<v8::Value> args[]);
  bool ProcessOutgoing(const int argc, v8::Handle<v8::Value> args[]);

 private:
  std::shared_ptr<Env> env_;
  std::deque<Filter> filters_;
};

#endif
