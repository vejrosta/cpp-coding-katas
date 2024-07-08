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

// Test case for removing an element from a list with multiple elements that is
// the first element
TEST(DoublyLinkedListTest, RemoveFirstElementFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.remove(ELEM_0);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

// Test case for removing an element from a list with multiple elements that is
// the last element
TEST(DoublyLinkedListTest, RemoveLastElementFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.remove(ELEM_2);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getTail()->data, ELEM_1);
}

// Test case for removing an element by index from an empty list
TEST(DoublyLinkedListTest, RemoveElementByIndexFromEmptyList) {
  DoublyLinkedList list{};

  list.removeByIndex(0);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element by index from a list with one element
TEST(DoublyLinkedListTest, RemoveElementByIndexFromSingleElementList) {
  DoublyLinkedList list{};

  list.push_back(5);
  list.removeByIndex(0);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element by index from a list with multiple elements
TEST(DoublyLinkedListTest, RemoveElementByIndexFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

// Test case for removing multiple elements by index from a list with multiple
// elements
TEST(DoublyLinkedListTest,
     RemoveMultipleElementsByIndexFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.removeByIndex(0);
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_1);
}

// Test case for removing an element by index from a list with multiple elements
// that is the first element
TEST(DoublyLinkedListTest, RemoveFirstElementByIndexFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.removeByIndex(0);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_1);
  EXPECT_EQ(list.getTail()->data, ELEM_2);
}

// Test case for removing an element by index from a list with multiple elements
// that is the last element
TEST(DoublyLinkedListTest, RemoveLastElementByIndexFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.removeByIndex(2);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getTail()->data, ELEM_1);
}

// Test case for removing an element by index from a list with multiple elements
// that is not the first or last element
TEST(DoublyLinkedListTest,
     RemoveElementByIndexFromMultipleElementsListNotFirstOrLast) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};
  int constexpr ELEM_3{4};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.push_back(ELEM_3);
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->data, ELEM_2);
  EXPECT_EQ(list.getTail()->data, ELEM_3);
}

// Test case for removing an element by out of range index by 1 element from a
// list with multiple elements
TEST(DoublyLinkedListTest,
     RemoveElementByOutOfRangeIndexFromMultipleElementsList) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};
  int constexpr ELEM_3{4};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.push_back(ELEM_3);
  list.removeByIndex(4);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->data, ELEM_1);
  EXPECT_EQ(list.getHead()->next->next->data, ELEM_2);
  EXPECT_EQ(list.getTail()->data, ELEM_3);
}

// Test case for removing an element by out of range index by 2 elements from a
// list with multiple elements
TEST(DoublyLinkedListTest,
     RemoveElementByOutOfRangeIndexFromMultipleElementsListByTwoElements) {
  DoublyLinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};
  int constexpr ELEM_3{4};

  list.push_back(ELEM_0);
  list.push_back(ELEM_1);
  list.push_back(ELEM_2);
  list.push_back(ELEM_3);
  list.removeByIndex(5);

  EXPECT_FALSE(list.empty());

  EXPECT_EQ(list.getHead()->data, ELEM_0);
  EXPECT_EQ(list.getHead()->next->data, ELEM_1);
  EXPECT_EQ(list.getHead()->next->next->data, ELEM_2);
  EXPECT_EQ(list.getTail()->data, ELEM_3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
