#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Elem {
  int data{};
  Elem *next{nullptr};
};

class LinkedList {
public:
  Elem *getHead() const;

  bool empty() const;
  void push_back(int value);
  void remove(int value);

private:
  Elem *head{nullptr};
};

#endif // LINKED_LIST_H
