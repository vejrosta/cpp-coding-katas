cmake_minimum_required(VERSION 3.10)

project(Quicksort)

# Create a library target for the Quicksort algorithm
add_library(quicksort_lib src/quicksort.cpp)

# Specify include directories for this target
target_include_directories(quicksort_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the testing subdirectory
enable_testing()
add_subdirectory(tests)