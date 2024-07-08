cmake_minimum_required(VERSION 3.10)

project(DoublyLinkedList)

# Create a library target for the linked list algorithm
add_library(doubly_linked_list_lib src/doubly_linked_list.cpp)

# Specify include directories for this target
target_include_directories(doubly_linked_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the testing subdirectory
enable_testing()
add_subdirectory(tests)