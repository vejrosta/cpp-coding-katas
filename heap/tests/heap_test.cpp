#include "heap.h"
#include <gtest/gtest.h>

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
  Heap heap{};
  heap.insert(42);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has one element which is popped
TEST(HeapTest, PopOneElement) {
  Heap heap{};
  heap.insert(42);
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
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 2);
}

// Test case for the heap has two elements and one popped
TEST(HeapTest, PopTwoElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  heap.pop();
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.size(), 1);
}

// Test case for the heap has two elements and we check the top
TEST(HeapTest, TopTwoElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  ASSERT_EQ(heap.top(), 17);
}

// Test case for the heap has two elements and we check the top and then pop
TEST(HeapTest, TopPopTwoElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
}

// Test case for the heap has three elements and we check the top and then pop
TEST(HeapTest, TopPopThreeElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  heap.insert(73);
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
  heap.pop();
  ASSERT_EQ(heap.top(), 73);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
