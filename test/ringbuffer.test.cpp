#include <gtest/gtest.h>

#include "../src/ringbuffer.h"

TEST(ringbuffer, initial_length_is_0) {
  auto buffer = RingBuffer(5);
  ASSERT_EQ(buffer.length(), 0);
}

TEST(ringbuffer, adding_increses_len) {
  auto buffer = RingBuffer(5);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 1);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 2);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 3);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 4);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 5);
}

TEST(ringbuffer, can_only_add_max_length_elements) {
  auto buffer = RingBuffer(5);
  for (int i = 0; i < 5; i++) {
    buffer.add(1);
  }
  ASSERT_EQ(buffer.length(), 5);

  buffer.add(1);
  buffer.add(1);
  ASSERT_EQ(buffer.length(), 5);
}

TEST(ringbuffer, reading_returns_items_in_order) {
  auto buffer = RingBuffer(5);
  for (int i = 0; i < 5; i++) {
    buffer.add(i);
  }

  for (int i = 0; i < 5; i++) {
    int result;
    ASSERT_TRUE(buffer.remove(&result));
    ASSERT_EQ(result, i);
  }
}