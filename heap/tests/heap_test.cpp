#include "heap.h"
#include <gtest/gtest.h>

Heap heapify(std::vector<int> const &heap_data) {
  Heap heap{};
  for (auto const &value : heap_data) {
    heap.insert(value);
  }
  return heap;
}

void topAndPopThenCheck(Heap &heap, std::vector<int> const &top) {
  for (auto const &value : top) {
    ASSERT_EQ(heap.top(), value);
    heap.pop();
  }
}

// Test case for the heap is empty
TEST(HeapTest, Empty) {
  Heap heap{};
  ASSERT_TRUE(heap.empty());
}

// Test case for pop on an empty heap
TEST(HeapTest, PopEmpty) {
  Heap heap{};
  heap.pop();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for the heap has one element
TEST(HeapTest, OneElement) {
  auto heap{heapify({42})};
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has one element which is popped
TEST(HeapTest, PopOneElement) {
  auto heap{heapify({42})};
  heap.pop();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for the heap has one element and we check the top
TEST(HeapTest, TopOneElement) {
  Heap heap{};
  heap.insert(42);
  ASSERT_EQ(heap.top(), 42);
}

// Test case for the heap has two elements
TEST(HeapTest, TwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
}

// Test case for the heap has two elements and one popped
TEST(HeapTest, PopTwoElements) {
  auto heap{heapify({42, 17})};
  heap.pop();
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has two elements and we check the top
TEST(HeapTest, TopTwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_EQ(heap.top(), 17);
}

// Test case for the heap has two elements and we check the top and then pop
TEST(HeapTest, TopPopTwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
}

// Test case for the heap has three elements and we check the top and then pop
TEST(HeapTest, TopPopThreeElements) {
  auto heap{heapify({42, 17, 73})};
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
  heap.pop();
  ASSERT_EQ(heap.top(), 73);
}

// Test case for the heap has five elements and we check the top and then pop
TEST(HeapTest, TopPopFiveElements) {
  auto heap{heapify({42, 17, 73, 23, 11})};
  topAndPopThenCheck(heap, {11, 17, 23, 42, 73});
}

// Test case for the heap has 10 elements and we check the top and then pop
TEST(HeapTest, TopPopTenElements) {
  auto heap{heapify({42, 17, 73, 23, 11, 99, 37, 31, 7, 53})};
  topAndPopThenCheck(heap, {7, 11, 17, 23, 31, 37, 42, 53, 73, 99});
}

// Test case for finding an element in the empty heap
TEST(HeapTest, FindEmpty) {
  Heap heap{};
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is not there
TEST(HeapTest, FindNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is there
TEST(HeapTest, FindNonEmptyThere) {
  auto heap{heapify({17, 73, 53})};
  ASSERT_TRUE(heap.find(73));
}

// Test case for clearing the empty heap
TEST(HeapTest, ClearEmpty) {
  Heap heap{};
  heap.clear();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for clearing the non-empty heap
TEST(HeapTest, ClearNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  heap.clear();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for removing an element from the empty heap
TEST(HeapTest, RemoveEmpty) {
  Heap heap{};
  heap.remove(42);
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for removing an element from non-empty heap which is not there
TEST(HeapTest, RemoveNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  heap.remove(42);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 3);
}

// Test case for removing an element from non-empty heap which is there
TEST(HeapTest, RemoveNonEmptyThere) {
  auto heap{heapify({17, 73, 53})};
  heap.remove(73);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
  ASSERT_FALSE(heap.find(73));
  ASSERT_EQ(heap.top(), 17);
}

// Test case for removing an element from non-empty heap which is there
TEST(HeapTest, RemoveNonEmptyThereTop) {
  auto heap{heapify({17, 53, 73})};
  heap.remove(17);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
  ASSERT_FALSE(heap.find(17));
  ASSERT_EQ(heap.top(), 53);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
