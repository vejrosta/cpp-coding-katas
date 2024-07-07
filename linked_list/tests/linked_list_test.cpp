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

// Test case for a list with multiple elements
TEST(LinkedListTest, MultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);

  EXPECT_FALSE(list.empty());

  Elem *current{list.getHead()};
  EXPECT_EQ(current->data, ELEM_0);
  current = current->next;
  EXPECT_EQ(current->data, ELEM_1);
  current = current->next;
  EXPECT_EQ(current->data, ELEM_2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
