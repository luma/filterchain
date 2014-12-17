// © Copyright 2013 TokBox. All Rights Reserved.
#ifndef TEST_TEST_UTIL_H_
#define TEST_TEST_UTIL_H_

#include <log4cxx/basicconfigurator.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
// #include "core/MantisServer.hpp"

using ::testing::_;
using ::testing::Return;

class Util {
 public:
  static int RunTests(int argc, char** argv) {
    // mantis_static_initializer staticinit {"conf/log4cxx.properties"};

    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    int result = RUN_ALL_TESTS();

    return result;
  }
};

#endif  // TEST_TEST_UTIL_H_
