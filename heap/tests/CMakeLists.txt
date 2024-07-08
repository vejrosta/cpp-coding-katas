# Assuming you have GoogleTest set up globally or locally
add_executable(heap_tests heap_test.cpp)

# Link both GoogleTest and heap_lib to the test executable
target_link_libraries(heap_tests gtest gtest_main heap_lib)

# Register the test executable with CTest
add_test(NAME HeapTests COMMAND heap_tests)