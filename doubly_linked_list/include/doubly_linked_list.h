#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
  int data{};
  Node *prev{nullptr};
  Node *next{nullptr};
};

class DoublyLinkedList {
public:
  ~DoublyLinkedList();

  Node *getHead() const;
  Node *getTail() const;

  bool empty() const;
  void clear();

private:
  Node *head{nullptr};
  Node *tail{nullptr};
};

#endif // DOUBLY_LINKED_LIST_H
