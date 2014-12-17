#ifndef RTP_PACKET_H_
#define RTP_PACKET_H_

typedef std::shared_ptr<uint8_t> BufferType;

class RtpPacket {
 public:
  RtpPacket(const uint8_t* data, size_t len)
    : len_(len) {

    buffer_ = BufferType(static_cast<uint8_t*>(malloc(len)), free);
    memcpy(buffer_.get(), data, len);
  }

  ~RtpPacket() {}

 public:
  uint8_t getPayloadType() const {
    return buffer_.get()[1] &= 0x7F;  // 0111 1111
  }

  size_t size() const { return len_; }

 private:
  BufferType buffer_;
  size_t len_;
};

#endif