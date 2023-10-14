cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(This GameTests)

# set(Sources
#   Test_SystemPlayerThrust.cpp
# )

file(GLOB_RECURSE Sources 
    "*.cpp" 
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Asteroids
)

add_test(
  NAME ${This}
  COMMAND ${This}
)

# project(${This} C CXX)  # Set the name of your test project

message(STATUS "Executing CMakeLists.txt in the 'test' directory")

# add_executable(
#   hello_test
#   hello_test.cc
# )
# target_link_libraries(
#   hello_test
#   GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)

# file(GLOB_RECURSE TEST_SOURCES "*.cpp")  # Discover test source files recursively

# add_executable(GameTests ${TEST_SOURCES})  # Create an executable for the tests

# target_link_libraries(GameTests gtest gtest_main CTEST_MEMORYCHECK_COMMAND_OPTIONSGameLibrary)  # Link libraries

# add_test(NAME AllTests COMMAND GameTests)  # Define a test target for all tests