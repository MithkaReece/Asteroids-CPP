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

message(STATUS "Executing CMakeLists.txt in the 'test' directory")
