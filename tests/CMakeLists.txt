cmake_minimum_required(VERSION 3.14.0)  # (1)

set(TEST_EXECUTABLE your-test)  # (2)
set(TEST_NAME test-name)
set(UNIT_UNDER_TEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)  # (3)



add_executable(
    ${TEST_EXECUTABLE} example_add.cpp
)
target_link_libraries(${TEST_EXECUTABLE}
  #gmock  # (5)
 # gmock_main
   gtest_main
)
target_include_directories(${TEST_EXECUTABLE} PUBLIC
  ${UNIT_UNDER_TEST_INCLUDE_DIR}  # (6)
)

add_test(${TEST_NAME} ${TEST_EXECUTABLE})


