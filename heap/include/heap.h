#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
protected:
  Heap() = default;
  std::vector<int> heap_data{};

public:
  virtual ~Heap() = default;

  void insert(int value);
  void remove(int value);
  void clear();
  int size();
  bool empty();
  bool find(int value);
  int top();
  void pop();

private:
  virtual bool inOrder(int parent, int child) = 0;
  void heapify_down(int current);
  void heapify_up(int current);
  int heap_size{};
};

class MinHeap : public Heap {
protected:
  bool inOrder(int parent, int child) override {
    // For MinHeap, parent should be less than or equal to child
    return heap_data[parent] <= heap_data[child];
  }
};

class MaxHeap : public Heap {
protected:
  bool inOrder(int parent, int child) override {
    // For MaxHeap, parent should be greater than or equal to child
    return heap_data[parent] >= heap_data[child];
  }
};

#endif // HEAP_H
