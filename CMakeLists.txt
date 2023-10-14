message(STATUS "Executing CMakeLists.txt in the 'main' directory")

cmake_minimum_required(VERSION 3.12)

set(This Asteroids)

project(${This})

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

# Create project into a library
add_library(${This} STATIC ${SOURCES} ${header_dir_list})

target_link_libraries(${This} PUBLIC sfml-system sfml-graphics sfml-audio sfml-window)

# Create executable and use library created about
add_executable(AsteroidsExecutable src/main.cpp)
# Link the "Asteroids" library to the executable
target_link_libraries(AsteroidsExecutable PRIVATE Asteroids)

# Include the header directories in the target
target_include_directories(
  ${This}
    PUBLIC
    ${header_dir_list} # Recursive
)



# ===============================================
# ------------------- Testing -------------------
# ===============================================

set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)
# Include the "test" directory for building tests
add_subdirectory(test)

# Actually run the test
add_custom_target(run_tests COMMAND hello_test)
# add_custom_target(run_all_tests)
# add_dependencies(run_all_tests hello_test)
