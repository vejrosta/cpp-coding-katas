#include "heap.h"
#include <algorithm>

bool Heap::empty() { return heap_size == 0; }

int Heap::size() { return heap_size; }

void Heap::insert(int value) {
  heap_data.push_back(value);
  ++heap_size;

  heapify_up(heap_size - 1);
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
  heapify_down(0);
}

bool Heap::find(int value) {
  return std::find(heap_data.begin(), heap_data.end(), value) !=
         heap_data.end();
}

int Heap::top() { return heap_data[0]; }

void Heap::clear() {
  heap_data.clear();
  heap_size = 0;
}

void Heap::remove(int value) {
  for (int i{}; i < heap_size; ++i) {
    if (heap_data[i] == value) {
      std::swap(heap_data[i], heap_data[heap_size - 1]);
      heap_data.pop_back();
      --heap_size;
      heapify_down(i);
      return;
    }
  }
}

void Heap::heapify_down(int current) {
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

void Heap::heapify_up(int current) {
  while (current != 0) {
    int parent{(current - 1) / 2};
    if (heap_data[current] >= heap_data[parent]) {
      return;
    }
    std::swap(heap_data[current], heap_data[parent]);
    current = parent;
  }
}