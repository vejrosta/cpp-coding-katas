# Assuming you have GoogleTest set up globally or locally
add_executable(doubly_linked_list_tests doubly_linked_list_test.cpp)

# Link both GoogleTest and doubly_linked_list_lib to the test executable
target_link_libraries(doubly_linked_list_tests gtest gtest_main doubly_linked_list_lib)

# Register the test executable with CTest
add_test(NAME DoublyLinkedListTests COMMAND doubly_linked_list_tests)