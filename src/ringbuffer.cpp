#include "ringbuffer.h"
#include <algorithm>

RingBuffer::RingBuffer(int _maxLength) {
  maxLength = _maxLength;
  data = new int[maxLength];
  r = 0;
  w = 0;
  len = 0;
}

void RingBuffer::add(int value) {
  data[w] = value;
 
  w = (w + 1) % maxLength;
  if (len == maxLength) {
    r = (r + 1) % maxLength;
  }

  len = std::min(maxLength, len + 1);
}

bool RingBuffer::remove(int *result) {
  if (length() > 0) {
    *result = data[r];
    len--;
    r = (r + 1) % maxLength;
    return true;
  }
  return false;
}

int RingBuffer::length(){
    return len;
};