cmake_minimum_required(VERSION 3.12)
project(Asteroids)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)


# Specify the source directory
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Set the include directories
include_directories(${SRC_DIR})



set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

file(GLOB_RECURSE SOURCES 
    "src/*.cpp" 
    "src/scenes/*.cpp"
    "src/systems/*.cpp" 
    "src/entities/*.cpp" 
    "src/components/*.cpp" 
)

add_executable(Asteroids ${SOURCES})

target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-audio sfml-window)