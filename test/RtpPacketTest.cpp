// © Copyright 2013 TokBox. All Rights Reserved.
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test/Util.h"
#include "test/Samples.h"

#include "RtpPacket.hpp"

TEST(RtpPacketTest, payloadType) {
  uint8_t data[] = {
      0x90,  // v = 2, X = 1
      0x01,  // PT = 1
      0xFF, 0xFF,  // sn = 0xffff
      0x00, 0x00, 0x00, 0x00,  // time stamp
      0x12, 0x34, 0x56, 0x78,  // time stamp
      0x0F, 0x0F,  // Header extension: "defined by profile"
      0x00, 0x01,  // header len
      0x11, 0x11, 0x11, 0x11,  // Header extension data
      0x22, 0x22, 0x22, 0x22,  // Rtp data
  };

  size_t len = sizeof(data);

  RtpPacket packet(data, len);
  ASSERT_EQ(packet.getPayloadType(), 0x01);
}


int main(int argc, char **argv) {
  return Util::RunTests(argc, argv);
}
