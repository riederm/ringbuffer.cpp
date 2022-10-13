#include "ringbuffer.h"
#include <algorithm>

RingBuffer::RingBuffer(int _maxLength) {
  maxLength = _maxLength;
  data = new int[maxLength];
  r = 0;
  w = 0;
  len = 0;
}

void RingBuffer::move_rd() {
  r = (r + 1) % maxLength;
  if (w == r) {
    // we just moved onto the read-ptr
    move_wr();
  }
}

void RingBuffer::move_wr() {
  w = (w + 1) % maxLength;
  if (w == r) {
    // we just moved onto the read-ptr
    move_rd();
  }
}

void RingBuffer::add(int value) {
  data[w] = value;
  len = std::min(maxLength, len + 1);
  move_wr();
}

bool RingBuffer::remove(int *result) {
  if (length() > 0) {
    *result = data[r];
    len--;
    move_rd();
    return true;
  }
  return false;
}

int RingBuffer::length(){
    return len;
};