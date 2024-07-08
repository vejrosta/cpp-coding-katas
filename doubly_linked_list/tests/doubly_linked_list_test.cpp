#include "doubly_linked_list.h"
#include <gtest/gtest.h>

// Test case for an empty list
TEST(DoublyLinkedListTest, EmptyList) {
  DoublyLinkedList list{};

  EXPECT_TRUE(list.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
