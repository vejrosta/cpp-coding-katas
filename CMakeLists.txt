cmake_minimum_required(VERSION 3.10)

project(MyProjects VERSION 1.0)

# Specify the C++ standard globally
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the subprojects
add_subdirectory(quicksort)