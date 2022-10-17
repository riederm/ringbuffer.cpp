add_test([=[ringbuffer.initial_length_is_0]=]  /workspace/ringbuffer.cpp/bin/unit_tests [==[--gtest_filter=ringbuffer.initial_length_is_0]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ringbuffer.initial_length_is_0]=]  PROPERTIES WORKING_DIRECTORY /workspace/ringbuffer.cpp/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==] LABELS unit)
set(  unit_tests_TESTS ringbuffer.initial_length_is_0)
