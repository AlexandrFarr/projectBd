cmake_minimum_required(VERSION 3.14.0)  # (1)



set(TEST_EXECUTABLE your-test)  # (2)
set(TEST_NAME test-name)
set(UNIT_UNDER_TEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MAIN_SRC_DIR ../src)
set (MAIN_SOURCE ${MAIN_SRC_DIR}/example.cpp )


#===============include Google Tests==========================#
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)  # (3)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#===============================================================#


# если сделаем статическую библиотеку из src то убираем ${MAIN_SOURCE}
add_executable(
    your-test example_add.cpp  ${MAIN_SOURCE} ${MAIN_SRC_DIR}/connectpost.cpp
)

target_link_libraries(your-test
  #gmock  # (5)
 # gmock_main
   gtest_main

)
### there ( нужно подключать статическую библиотеку из src)
target_include_directories(your-test PUBLIC
    ${MAIN_SRC_DIR}
)

#===================== LINKING LIBRARIES =======================#
target_link_libraries(your-test Qt6::Widgets)
target_link_libraries(your-test Qt6::Sql)
#===============================================================#


add_test(${TEST_NAME} ${TEST_EXECUTABLE})


