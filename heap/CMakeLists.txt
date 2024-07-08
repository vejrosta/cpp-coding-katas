cmake_minimum_required(VERSION 3.10)

project(Heap)

# Create a library target for the heap algorithm
add_library(heap_lib src/heap.cpp)

# Specify include directories for this target
target_include_directories(heap_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the testing subdirectory
enable_testing()
add_subdirectory(tests)