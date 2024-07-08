#include "doubly_linked_list.h"
#include <gtest/gtest.h>

// Test case for an empty list
TEST(DoublyLinkedListTest, EmptyList) {
  DoublyLinkedList list{};

  EXPECT_TRUE(list.empty());
}

// Test case for a list with one element
TEST(DoublyLinkedListTest, SingleElementList) {
  DoublyLinkedList list{};

  list.push_back(5);

  EXPECT_FALSE(list.empty());
}

// Test case for a list with multiple elements
TEST(DoublyLinkedListTest, MultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

// Test case with one element pushed to the front
TEST(DoublyLinkedListTest, PushFrontOneElement) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};

  list.push_front(ELEM_0);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getTail()->data, ELEM_0);
}

// Test case with multiple elements pushed to the front
TEST(DoublyLinkedListTest, PushFrontMultipleElements) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_front(ELEM_0);
  list.push_front(ELEM_1);
  list.push_front(ELEM_2);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_2);
  EXPECT_EQ(list.getHead()->next->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_0);
}

// Test case for pushing elements to the front and back
TEST(DoublyLinkedListTest, PushFrontAndBack) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};
  int constexpr ELEM_3{4};

  list.push_front(ELEM_0);
  list.push_back(ELEM_1);
  list.push_front(ELEM_2);
  list.push_back(ELEM_3);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_2);
  EXPECT_EQ(list.getHead()->next->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->next->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_3);
}

// Test case for removing an element from an empty list
TEST(DoublyLinkedListTest, RemoveElementFromEmptyList) {
  DoublyLinkedList list{};

  list.remove(5);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element from a list with one element that is not
// the element to remove
TEST(DoublyLinkedListTest, RemoveElementFromSingleElementList) {
  DoublyLinkedList list{};

  list.push_back(5);
  list.remove(3);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, 5);
  EXPECT_EQ(list.getTail()->data, 5);
}

// Test case for removing an element from a list with one element that is the
// element to remove
TEST(DoublyLinkedListTest, RemoveElementFromSingleElementListToRemove) {
  DoublyLinkedList list{};

  list.push_back(5);
  list.remove(5);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element from a list with multiple elements that is
// not the element to remove
TEST(DoublyLinkedListTest, RemoveElementFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.remove(5);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

// Test case for removing an element from a list with multiple elements that is
// the element to remove
TEST(DoublyLinkedListTest, RemoveElementFromMultipleElementsListToRemove) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.remove(ELEM_1);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
