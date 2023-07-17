cmake_minimum_required(VERSION 3.12)
project(Asteroids)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
add_executable(Asteroids main.cpp)

target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-audio sfml-window)