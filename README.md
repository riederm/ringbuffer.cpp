# ringbuffer.cpp

This is the ringbuffer programming example. [Here](https://en.wikipedia.org/wiki/Circular_buffer)  you can find some basic information about ringbuffers.

## How to build this project

```bash
git clone https://github.com/riederm/ringbuffer.cpp.git
cd ringbuffer.cpp
cmake -S. -Bbuild 
cmake --build build
```


## Running the tests
Either using `ctest`:
```
$ cd build
$ ctest

Running tests...
Test project /home/user/gtest-demo/build
    Start 1: unit
1/1 Test #1: unit .............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```

Or directly using `unit_tests`:
```
$ cd build 
$ ./bin/unit_tests

[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from example
[ RUN      ] test1
[       OK ] test1 (0 ms)
[ RUN      ] test2
[       OK ] test2 (0 ms)
[----------] 2 tests from example (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.

```