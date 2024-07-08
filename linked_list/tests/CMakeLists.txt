# Assuming you have GoogleTest set up globally or locally
add_executable(linked_list_tests linked_list_test.cpp)

# Link both GoogleTest and linked_list_lib to the test executable
target_link_libraries(linked_list_tests gtest gtest_main linked_list_lib)

# Register the test executable with CTest
add_test(NAME LinkedListTests COMMAND linked_list_tests)