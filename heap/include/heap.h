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
  std::vector<int> heap_data{};
  int heap_size{};
};

#endif // HEAP_H
