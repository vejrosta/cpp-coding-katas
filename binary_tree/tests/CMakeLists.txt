# Assuming you have GoogleTest set up globally or locally
add_executable(binary_tree_tests binary_tree_test.cpp)

# Link both GoogleTest and binary_tree_lib to the test executable
target_link_libraries(binary_tree_tests gtest gtest_main binary_tree_lib)

# Register the test executable with CTest
add_test(NAME BinaryTreeTests COMMAND binary_tree_tests)