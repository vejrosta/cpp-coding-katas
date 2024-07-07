#include "linked_list.h"
#include <gtest/gtest.h>
#include <vector>

// Test case for an empty vector
TEST(LinkedListTest, EmptyList) {
  LinkedList list{};

  EXPECT_TRUE(list.empty());
}

// Test case for a list with one element
TEST(LinkedListTest, SingleElementList) {
  LinkedList list{};
  list.push_back(5);

  EXPECT_FALSE(list.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
