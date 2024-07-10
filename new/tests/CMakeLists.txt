# Assuming you have GoogleTest set up globally or locally
add_executable(new_tests new_test.cpp)

# Link both GoogleTest and new_lib to the test executable
target_link_libraries(new_tests gtest gtest_main new_lib)

# Register the test executable with CTest
add_test(NAME NewTests COMMAND new_tests)