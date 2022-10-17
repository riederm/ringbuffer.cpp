#include "ringbuffer.h"
#include <algorithm>


RingBuffer::RingBuffer(int ml) {
  maxLength = ml;
  len = 0;
}

int RingBuffer::length() {
  return len;
}