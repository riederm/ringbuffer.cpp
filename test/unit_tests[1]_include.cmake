if(EXISTS "/workspace/ringbuffer.cpp/test/unit_tests[1]_tests.cmake")
  include("/workspace/ringbuffer.cpp/test/unit_tests[1]_tests.cmake")
else()
  add_test(unit_tests_NOT_BUILT unit_tests_NOT_BUILT)
endif()
