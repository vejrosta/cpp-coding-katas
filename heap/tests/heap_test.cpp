#include "heap.h"
#include <gtest/gtest.h>

MinHeap heapify(std::vector<int> const &heap_data) {
  MinHeap heap{};
  for (auto const &value : heap_data) {
    heap.insert(value);
  }
  return heap;
}

void topAndPopThenCheck(MinHeap &heap, std::vector<int> const &top) {
  for (auto const &value : top) {
    ASSERT_EQ(heap.top(), value);
    heap.pop();
  }
}

// Test case for the heap is empty
TEST(MinHeapTest, Empty) {
  MinHeap heap{};
  ASSERT_TRUE(heap.empty());
}

// Test case for pop on an empty heap
TEST(MinHeapTest, PopEmpty) {
  MinHeap heap{};
  heap.pop();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for the heap has one element
TEST(MinHeapTest, OneElement) {
  auto heap{heapify({42})};
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has one element which is popped
TEST(MinHeapTest, PopOneElement) {
  auto heap{heapify({42})};
  heap.pop();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for the heap has one element and we check the top
TEST(MinHeapTest, TopOneElement) {
  MinHeap heap{};
  heap.insert(42);
  ASSERT_EQ(heap.top(), 42);
}

// Test case for the heap has two elements
TEST(MinHeapTest, TwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
}

// Test case for the heap has two elements and one popped
TEST(MinHeapTest, PopTwoElements) {
  auto heap{heapify({42, 17})};
  heap.pop();
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has two elements and we check the top
TEST(MinHeapTest, TopTwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_EQ(heap.top(), 17);
}

// Test case for the heap has two elements and we check the top and then pop
TEST(MinHeapTest, TopPopTwoElements) {
  auto heap{heapify({42, 17})};
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
}

// Test case for the heap has three elements and we check the top and then pop
TEST(MinHeapTest, TopPopThreeElements) {
  auto heap{heapify({42, 17, 73})};
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
  heap.pop();
  ASSERT_EQ(heap.top(), 73);
}

// Test case for the heap has five elements and we check the top and then pop
TEST(MinHeapTest, TopPopFiveElements) {
  auto heap{heapify({42, 17, 73, 23, 11})};
  topAndPopThenCheck(heap, {11, 17, 23, 42, 73});
}

// Test case for the heap has 10 elements and we check the top and then pop
TEST(MinHeapTest, TopPopTenElements) {
  auto heap{heapify({42, 17, 73, 23, 11, 99, 37, 31, 7, 53})};
  topAndPopThenCheck(heap, {7, 11, 17, 23, 31, 37, 42, 53, 73, 99});
}

// Test case for finding an element in the empty heap
TEST(MinHeapTest, FindEmpty) {
  MinHeap heap{};
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is not there
TEST(MinHeapTest, FindNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is there
TEST(MinHeapTest, FindNonEmptyThere) {
  auto heap{heapify({17, 73, 53})};
  ASSERT_TRUE(heap.find(73));
}

// Test case for clearing the empty heap
TEST(MinHeapTest, ClearEmpty) {
  MinHeap heap{};
  heap.clear();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for clearing the non-empty heap
TEST(MinHeapTest, ClearNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  heap.clear();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for removing an element from the empty heap
TEST(MinHeapTest, RemoveEmpty) {
  MinHeap heap{};
  heap.remove(42);
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

// Test case for removing an element from non-empty heap which is not there
TEST(MinHeapTest, RemoveNonEmpty) {
  auto heap{heapify({17, 73, 53})};
  heap.remove(42);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 3);
}

// Test case for removing an element from non-empty heap which is there
TEST(MinHeapTest, RemoveNonEmptyThere) {
  auto heap{heapify({17, 73, 53})};
  heap.remove(73);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
  ASSERT_FALSE(heap.find(73));
  ASSERT_EQ(heap.top(), 17);
}

// Test case for removing an element from non-empty heap which is there
TEST(MinHeapTest, RemoveNonEmptyThereTop) {
  auto heap{heapify({17, 53, 73})};
  heap.remove(17);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
  ASSERT_FALSE(heap.find(17));
  ASSERT_EQ(heap.top(), 53);
}

// Test case for one general approval MaxHeap test
TEST(MaxHeapTest, General) {
  MaxHeap heap{};
  std::vector<int> elements = {42, 17, 73, 23, 11, 99, 37, 31, 7, 53};
  for (auto const &value : elements) {
    heap.insert(value);
  }
  ASSERT_EQ(heap.size(), 10);
  ASSERT_FALSE(heap.empty());
  ASSERT_TRUE(heap.find(73));
  ASSERT_EQ(heap.top(), 99);
  for (int i = 0; i < 10; ++i) {
    heap.pop();
  }
  ASSERT_TRUE(heap.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
