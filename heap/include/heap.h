#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
public:
  void insert(int value);
  void remove(int value);
  void clear();
  int size();
  bool empty();
  bool find(int value);
  int top();
  void pop();

private:
  bool inOrder(int parent, int child);
  void heapify_down(int current);
  void heapify_up(int current);
  std::vector<int> heap_data{};
  int heap_size{};
};

#endif // HEAP_H
