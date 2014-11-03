// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <map>
#include <string>
#include <v8.h>
// #include <include/libplatform/libplatform.h>
//#include <log4cxx/logger.h>

#include "../build/Config.h"

typedef v8::Persistent<v8::Context, v8::CopyablePersistentTraits<v8::Context>> PersistentContext;
typedef v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> PersistentFunction;

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(a) (sizeof((a)) / sizeof((a)[0]))
#endif

// #define LOG_MESG(message)\
//   LOG4CXX_DEBUG(logger, \
//       __FUNCTION__ << '[' << __LINE__ << ']' \
//       << ": " << message \
//       )

// #define LOG_MESG_(LEVEL, message)\
//   LOG4CXX_ ## LEVEL(logger, \
//       __FUNCTION__ << '[' << __LINE__ << ']' \
//       << ": " << message \
//       )

const char* ToCString(const v8::String::Utf8Value& value);
void ReportException(v8::Isolate* isolate, v8::TryCatch* try_catch);

#endif
