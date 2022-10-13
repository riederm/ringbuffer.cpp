add_library(ringbuffer)

target_sources(ringbuffer
  PRIVATE
    ringbuffer.cpp
  PUBLIC
    ringbuffer.h
  )

target_include_directories(ringbuffer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(ringbuffer
    PUBLIC
      "--coverage"
    )
  target_link_options(ringbuffer
    INTERFACE
      "--coverage"
    )
endif()
