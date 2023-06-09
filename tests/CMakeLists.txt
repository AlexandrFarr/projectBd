cmake_minimum_required(VERSION 3.14.0)  # (1)

set(TEST_EXECUTABLE your-test)  # (2)
set(TEST_NAME test-name)
set(UNIT_UNDER_TEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(UNIT_UNDER_TEST_SRC_DIR ../src)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)  # (3)



set(MAIN_SRC_DIR ../src)
set (MAIN_SOURCE
 ${MAIN_SRC_DIR}/example.cpp
)

add_executable(
    your-test example_add.cpp  ${MAIN_SOURCE}
)
target_link_libraries(your-test
  #gmock  # (5)
 # gmock_main
   gtest_main

)
### there
target_include_directories(your-test PUBLIC
  ${UNIT_UNDER_TEST_INCLUDE_DIR}
    ${MAIN_SRC_DIR}
)

add_test(${TEST_NAME} ${TEST_EXECUTABLE})


