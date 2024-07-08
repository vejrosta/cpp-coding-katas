#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  int data{};
  Node *next{nullptr};
};

class LinkedList {
public:
  ~LinkedList();

  Node *getHead() const;

  bool empty() const;
  void push_back(int value);
  void remove(int value);
  void clear();
  void removeByIndex(int index);

private:
  Node *head{nullptr};
};

#endif // LINKED_LIST_H
