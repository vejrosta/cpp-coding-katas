cmake_minimum_required(VERSION 3.10)

project(BinaryTree)

# Create a library target for the binary tree algorithms
add_library(binary_tree_lib src/binary_tree.cpp)

# Specify include directories for this target
target_include_directories(binary_tree_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the testing subdirectory
enable_testing()
add_subdirectory(tests)