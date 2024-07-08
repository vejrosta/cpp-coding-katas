#include "linked_list.h"

LinkedList::~LinkedList() { clear(); }

Node *LinkedList::getHead() const { return head; }

bool LinkedList::empty() const { return head == nullptr; }

void LinkedList::push_back(int value) {
  if (head == nullptr) {
    head = new Node{value};
  } else {
    auto current{head};
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node{value};
  }
}

void LinkedList::remove(int value) {
  if (head == nullptr) {
    return;
  }

  if (head->data == value) {
    auto tmp{head};
    head = head->next;
    delete tmp;
    return;
  }

  auto current{head};
  while (current->next != nullptr) {
    if (current->next->data == value) {
      auto temp{current->next};
      current->next = current->next->next;
      delete temp;
      return;
    }
    current = current->next;
  }
}

void LinkedList::removeByIndex(int index) {
  if (head == nullptr) {
    return;
  }

  if (index == 0) {
    auto tmp{head};
    head = head->next;
    delete tmp;
    return;
  }

  auto current{head};
  for (int i{}; i < index - 1; ++i) {
    if (current->next == nullptr) {
      return;
    }
    current = current->next;
  }

  auto tmp{current->next};
  if (tmp == nullptr) {
    return;
  }
  current->next = tmp->next;
  delete tmp;
}

void LinkedList::clear() {
  while (head != nullptr) {
    auto tmp{head};
    head = head->next;
    delete tmp;
  }
}
