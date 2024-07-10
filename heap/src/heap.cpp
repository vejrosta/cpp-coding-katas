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
  if (heap_size == 2) {
    std::swap(heap_data[0], heap_data[1]);
    heap_data.pop_back();
    heap_size = 1;
    return;
  }
  if (heap_size == 3) {
    std::swap(heap_data[0], heap_data[2]);
    heap_data.pop_back();
    --heap_size;
    if (heap_data[0] < heap_data[1]) {
      return;
    }
    std::swap(heap_data[0], heap_data[1]);
    return;
  }
  std::swap(heap_data[0], heap_data[heap_size - 1]);
  heap_data.pop_back();
  --heap_size;
  if (heap_data[0] < heap_data[1] && heap_data[0] < heap_data[2]) {
    return;
  } else if (heap_data[1] < heap_data[2]) {
    std::swap(heap_data[0], heap_data[1]);
  } else {
    std::swap(heap_data[0], heap_data[2]);
  }
}

int Heap::top() { return heap_data[0]; }