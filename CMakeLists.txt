cmake_minimum_required(VERSION 3.12)
project(Asteroids)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)

# Specify the source directory
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Set the include directories
include_directories(${SRC_DIR})

MACRO(HEADER_DIRECTORIES return_list)
    # Gather .h and .hpp files
    FILE(GLOB_RECURSE new_list "${SRC_DIR}/*.h" "${SRC_DIR}/*.hpp")

    # Set up the list to store directories
    SET(dir_list "")

    # Extract the directories from the file paths
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()

    # Remove any duplicates
    LIST(REMOVE_DUPLICATES dir_list)

    #Return final list
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_dir_list)

# Calculate the count and display the message
list(LENGTH header_dir_list header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list_count} header directories.")



set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

file(GLOB_RECURSE SOURCES 
    "src/*.cpp" 
)

add_executable(Asteroids ${SOURCES})

target_link_libraries(Asteroids PRIVATE sfml-system sfml-graphics sfml-audio sfml-window)

# Include the header directories in the target
target_include_directories(
    Asteroids
    PUBLIC
    ${header_dir_list} # Recursive
)
