#include <gtest/gtest.h>
#include <vector>
#include "quicksort.h"

// Test case for an empty vector
TEST(QuicksortTest, EmptyVector) {
    std::vector<int> input;
    std::vector<int> expected;

    quicksort(input);
    EXPECT_EQ(input, expected);
}

// Test case for a vector with one element
TEST(QuicksortTest, SingleElementVector) {
    std::vector<int> input = {5};
    std::vector<int> expected = {5};

    quicksort(input);
    EXPECT_EQ(input, expected);
}

// Test case for a vector with multiple elements in ascending order
TEST(QuicksortTest, AscendingOrderVector) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    quicksort(input);
    EXPECT_EQ(input, expected);
}

// Test case for a vector with multiple elements in descending order
TEST(QuicksortTest, DescendingOrderVector) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    quicksort(input);
    EXPECT_EQ(input, expected);
}

// Test case for a vector with duplicate elements
TEST(QuicksortTest, DuplicateElementsVector) {
    std::vector<int> input = {3, 2, 1, 2, 3};
    std::vector<int> expected = {1, 2, 2, 3, 3};

    quicksort(input);
    EXPECT_EQ(input, expected);
}

// Test case for a large vector
TEST(QuicksortTest, LargeVector) {
    std::vector<int> input = {9, 5, 2, 7, 1, 8, 3, 6, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    quicksort(input);
    EXPECT_EQ(input, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}