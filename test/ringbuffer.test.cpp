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

TEST(ringbuffer, reading_after_wrap_around) {
  // GIVEN a full ringbuffer 0-4
  auto buffer = RingBuffer(5);
  for (int i = 0; i < 5; i++) {
    buffer.add(i);
  }

  // WHEN I add two additional items 5,6
  buffer.add(5);
  buffer.add(6);

  // THEN I expect 2-6
  for (int i = 2; i < 7; i++) {
    int result;
    ASSERT_TRUE(buffer.remove(&result));
    ASSERT_EQ(result, i);
  }
}

TEST(ringbuffer, reading_empty_buffer_returns_false) {
  // GIVEN an empty buffer
  auto buffer = RingBuffer(5);

  // WHEN I read from it
  int result;
  bool success = buffer.remove(&result);

  // THEN I expect false
  ASSERT_FALSE(success);
}

TEST(ringbuffer, adding_a_lot_of_entries) {
  // GIVEN an empty buffer
  auto buffer = RingBuffer(5);

  // WHEN I add a lot of elements 0-99
  for(int i=0; i<100; i++){
    buffer.add(i);
  }

  // THEN I the elements 95, 96, 97, 98, 99
  for (int i = 95; i < 100; i++) {
    int result;
    ASSERT_TRUE(buffer.remove(&result));
    ASSERT_EQ(result, i);
  }
}