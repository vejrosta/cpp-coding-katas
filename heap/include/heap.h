#ifndef HEAP_H
#define HEAP_H

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
};

#endif // HEAP_H
