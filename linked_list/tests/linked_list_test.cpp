#include "linked_list.h"
#include <gtest/gtest.h>
#include <vector>

void fillList(LinkedList &list, std::vector<int> const &values) {
  for (auto const value : values) {
    list.push_back(value);
  }
}

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

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});

  EXPECT_FALSE(list.empty());

  Elem *current{list.getHead()};
  EXPECT_EQ(current->data, ELEM_0);
  current = current->next;
  EXPECT_EQ(current->data, ELEM_1);
  current = current->next;
  EXPECT_EQ(current->data, ELEM_2);
}

// Test case for removing an element from an empty list
TEST(LinkedListTest, RemoveElementFromEmptyList) {
  LinkedList list{};

  list.remove(5);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element from a list with one element that is not
// the element to remove
TEST(LinkedListTest, RemoveElementFromSingleElementList) {
  LinkedList list{};

  list.push_back(5);
  list.remove(3);

  EXPECT_FALSE(list.empty());
}

// Test case for removing an element from a list with one element that is the
// element to remove
TEST(LinkedListTest, RemoveElementFromSingleElementList2) {
  LinkedList list{};

  list.push_back(5);
  list.remove(5);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element from a list with multiple elements
TEST(LinkedListTest, RemoveElementFromMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.remove(ELEM_1);

  EXPECT_FALSE(list.empty());

  Elem *current{list.getHead()};
  EXPECT_EQ(current->data, ELEM_0);
  current = current->next;
  EXPECT_EQ(current->data, ELEM_2);
}

// Test case for removing multiple elements from a list with multiple elements
TEST(LinkedListTest, RemoveMultipleElementsFromMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.remove(ELEM_0);
  list.remove(ELEM_2);

  EXPECT_FALSE(list.empty());

  Elem *current{list.getHead()};
  EXPECT_EQ(current->data, ELEM_1);
  current = current->next;
  EXPECT_EQ(current, nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
