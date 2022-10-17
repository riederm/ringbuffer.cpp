#include <gtest/gtest.h>

#include "../src/ringbuffer.h"

TEST(ringbuffer, initial_length_is_0) {
  auto buffer = RingBuffer(5);
  ASSERT_EQ(buffer.length(), 0);
}