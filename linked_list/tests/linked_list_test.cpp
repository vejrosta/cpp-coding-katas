#include "linked_list.h"
#include <gtest/gtest.h>
#include <vector>

void fillList(LinkedList &list, std::vector<int> const &values) {
  for (auto const value : values) {
    list.push_back(value);
  }
}

void checkList(LinkedList &list, std::vector<int> const &values) {
  auto *current{list.getHead()};
  int xorValue{};
  int sumValue{};
  for (auto const value : values) {
    xorValue ^= value;
    sumValue += value;
  }
  for (auto const value : values) {
    xorValue ^= current->data;
    sumValue -= current->data;
    current = current->next;
  }
  EXPECT_EQ(xorValue, 0);
  EXPECT_EQ(sumValue, 0);
  EXPECT_EQ(current, nullptr);
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

  checkList(list, {ELEM_0, ELEM_1, ELEM_2});
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
  checkList(list, {ELEM_0, ELEM_2});
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
  checkList(list, {ELEM_1});
}

// Test case for clearing an empty list
TEST(LinkedListTest, ClearEmptyList) {
  LinkedList list{};

  list.clear();

  EXPECT_TRUE(list.empty());
}

// Test case for clearing a list with one element
TEST(LinkedListTest, ClearSingleElementList) {
  LinkedList list{};

  list.push_back(5);
  list.clear();

  EXPECT_TRUE(list.empty());
}

// Test case for clearing a list with multiple elements
TEST(LinkedListTest, ClearMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.clear();

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element by index from an empty list
TEST(LinkedListTest, RemoveElementByIndexFromEmptyList) {
  LinkedList list{};

  list.removeByIndex(0);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element by index from a list with one element
TEST(LinkedListTest, RemoveElementByIndexFromSingleElementList) {
  LinkedList list{};

  list.push_back(5);
  list.removeByIndex(0);

  EXPECT_TRUE(list.empty());
}

// Test case for removing an element by index from a list with multiple elements
TEST(LinkedListTest, RemoveElementByIndexFromMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());
  checkList(list, {ELEM_0, ELEM_2});
}

// Test case for removing multiple elements by index from a list with multiple
// elements
TEST(LinkedListTest, RemoveMultipleElementsByIndexFromMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{3};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.removeByIndex(0);
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());
  checkList(list, {ELEM_1});
}

// Test case for removing an element by index with an index out of bounds
TEST(LinkedListTest, RemoveElementByIndexOutOfBounds) {
  LinkedList list{};
  int constexpr ELEM_0{1};

  fillList(list, {ELEM_0});
  list.removeByIndex(1);

  EXPECT_FALSE(list.empty());
  checkList(list, {ELEM_0});
}

// Test case for removing duplicates from an empty list
TEST(LinkedListTest, RemoveDuplicatesEmptyList) {
  LinkedList list{};

  list.removeDuplicates();

  EXPECT_TRUE(list.empty());
}

// Test case for removing duplicates from a list with one element
TEST(LinkedListTest, RemoveDuplicatesSingleElementList) {
  LinkedList list{};

  list.push_back(5);
  list.removeDuplicates();

  EXPECT_FALSE(list.empty());
}

// Test case for removing duplicates from a list with multiple elements
TEST(LinkedListTest, RemoveDuplicatesMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{1};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2});
  list.removeDuplicates();

  EXPECT_FALSE(list.empty());
  checkList(list, {ELEM_0, ELEM_1});
}

// Test case for removing multiple duplicates from a list with multiple elements
TEST(LinkedListTest, RemoveMultipleDuplicatesFromMultipleElementsList) {
  LinkedList list{};
  int constexpr ELEM_0{1};
  int constexpr ELEM_1{2};
  int constexpr ELEM_2{1};
  int constexpr ELEM_3{2};

  fillList(list, {ELEM_0, ELEM_1, ELEM_2, ELEM_3});
  list.removeDuplicates();

  EXPECT_FALSE(list.empty());
  checkList(list, {ELEM_0, ELEM_1});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
