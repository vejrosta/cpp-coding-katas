cmake_minimum_required(VERSION 3.10)

project(New)

# Create a library target for the linked list algorithm
add_library(new_lib src/new.cpp)

# Specify include directories for this target
target_include_directories(new_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the testing subdirectory
enable_testing()
add_subdirectory(tests)