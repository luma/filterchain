// © Copyright 2014 TokBox. All Rights Reserved.
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/logmanager.h>

#include "Env.hpp"
#include "FilterChain.hpp"


int main(int argc, char *argv[]) {
  // int err = 0;

  // log4cxx::PropertyConfigurator::configure("conf/log4cxx.properties");

  std::shared_ptr<Env> env;
  FilterChain filters(env);
  filters.Add("../filters/foo_filter.js");
  // filters.Add("../filters/bar_filter.js");

  // @todo build a fake RtpPacket or RtcpPacket object as the filter argument
  // v8::Local<v8::Value> result;
  // v8::Handle<v8::Value> args[1] = {
  //   v8::String::NewFromUtf8(env->GetIsolate(), "Packet", v8::String::kInternalizedString)
  // };

  // printf("Process Incoming:\n");
  // if (!filters.ProcessIncoming(ARRAY_SIZE(args), args)) {
  //   printf(" Discard Incoming Packet!\n");
  // } else {
  //   printf(" Process Incoming Packet!\n");
  // }

  // printf("\n\nProcess Outgoing:\n");
  // if (!filters.ProcessOutgoing(ARRAY_SIZE(args), args)) {
  //   printf(" Discard Outgoing Packet\n");
  // } else {
  //   printf(" Process Outgoing Packet\n");
  // }


  // v8::V8::Dispose();
  return 0;
}
