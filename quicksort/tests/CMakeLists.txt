# Assuming you have GoogleTest set up globally or locally
add_executable(quicksort_tests quicksort_test.cpp)

# Link both GoogleTest and quicksort_lib to the test executable
target_link_libraries(quicksort_tests gtest gtest_main quicksort_lib)

# Register the test executable with CTest
add_test(NAME QuicksortTests COMMAND quicksort_tests)