#include "heap.h"

bool Heap::empty() { return heap_size == 0; }

int Heap::size() { return heap_size; }

void Heap::insert(int value) {
  heap_data.push_back(value);
  ++heap_size;

  int current{heap_size - 1};
  while (current != 0) {
    int parent{(current - 1) / 2};
    if (heap_data[current] >= heap_data[parent]) {
      return;
    }
    std::swap(heap_data[current], heap_data[parent]);
    current = parent;
  }
}

void Heap::pop() {
  if (heap_size == 0) {
    return;
  }
  if (heap_size == 1) {
    heap_data.pop_back();
    heap_size = 0;
    return;
  }
  std::swap(heap_data[0], heap_data[heap_size - 1]);
  heap_data.pop_back();
  --heap_size;
  int current{0};
  while (current < heap_size) {
    int left{2 * current + 1};
    int right{2 * current + 2};
    if (left >= heap_size) {
      return;
    }
    if (right >= heap_size) {
      if (heap_data[current] <= heap_data[left]) {
        return;
      }
      std::swap(heap_data[current], heap_data[left]);
      return;
    }
    if (heap_data[current] <= heap_data[left] &&
        heap_data[current] <= heap_data[right]) {
      return;
    }
    if (heap_data[left] < heap_data[right]) {
      std::swap(heap_data[current], heap_data[left]);
      current = left;
    } else {
      std::swap(heap_data[current], heap_data[right]);
      current = right;
    }
  }
}

bool Heap::find(int value) {
  for (int i = 0; i < heap_size; ++i) {
    if (heap_data[i] == value) {
      return true;
    }
  }
  return false;
}

int Heap::top() { return heap_data[0]; }