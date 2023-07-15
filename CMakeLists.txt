cmake_minimum_required(VERSION 3.12)
project(Asteroids)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)


add_executable(Asteroids main.cpp)

target_link_libraries(Asteroids PRIVATE sfml-graphics sfml-audio)