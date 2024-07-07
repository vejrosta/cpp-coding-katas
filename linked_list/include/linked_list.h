#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Elem {
  int data{};
  Elem *next{nullptr};
};

class LinkedList {
public:
  bool empty() const;
  void push_back(int value);

private:
  Elem *head{nullptr};
};

#endif // LINKED_LIST_H
