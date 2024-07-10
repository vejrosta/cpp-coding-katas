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

// Test case for the heap has five elements and we check the top and then pop
TEST(HeapTest, TopPopFiveElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  heap.insert(73);
  heap.insert(23);
  heap.insert(11);
  ASSERT_EQ(heap.top(), 11);
  heap.pop();
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 23);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
  heap.pop();
  ASSERT_EQ(heap.top(), 73);
}

// Test case for the heap has 10 elements and we check the top and then pop
TEST(HeapTest, TopPopTenElements) {
  Heap heap{};
  heap.insert(42);
  heap.insert(17);
  heap.insert(73);
  heap.insert(23);
  heap.insert(11);
  heap.insert(99);
  heap.insert(37);
  heap.insert(31);
  heap.insert(7);
  heap.insert(53);
  ASSERT_EQ(heap.top(), 7);
  heap.pop();
  ASSERT_EQ(heap.top(), 11);
  heap.pop();
  ASSERT_EQ(heap.top(), 17);
  heap.pop();
  ASSERT_EQ(heap.top(), 23);
  heap.pop();
  ASSERT_EQ(heap.top(), 31);
  heap.pop();
  ASSERT_EQ(heap.top(), 37);
  heap.pop();
  ASSERT_EQ(heap.top(), 42);
  heap.pop();
  ASSERT_EQ(heap.top(), 53);
  heap.pop();
  ASSERT_EQ(heap.top(), 73);
  heap.pop();
  ASSERT_EQ(heap.top(), 99);
}

// Test case for finding an element in the empty heap
TEST(HeapTest, FindEmpty) {
  Heap heap{};
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is not there
TEST(HeapTest, FindNonEmpty) {
  Heap heap{};
  heap.insert(17);
  heap.insert(73);
  heap.insert(53);
  ASSERT_FALSE(heap.find(42));
}

// Test case for finding an element in non-empty heap which is there
TEST(HeapTest, FindNonEmptyThere) {
  Heap heap{};
  heap.insert(17);
  heap.insert(73);
  heap.insert(53);
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
  Heap heap{};
  heap.insert(17);
  heap.insert(73);
  heap.insert(53);
  heap.clear();
  ASSERT_TRUE(heap.empty());
  ASSERT_EQ(heap.size(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
