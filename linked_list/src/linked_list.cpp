#include "linked_list.h"
#include <unordered_map>

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
      auto tmp{current->next};
      current->next = current->next->next;
      delete tmp;
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

void LinkedList::removeDuplicates() {
  std::unordered_map<int, int> elementCounter;

  auto current{head};
  while (current != nullptr) {
    ++elementCounter[current->data];
    current = current->next;
  }

  current = head;
  Node *previous{nullptr};
  while (current != nullptr) {
    if (--elementCounter[current->data]) {
      if (previous != nullptr) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      Node *tmp{current};
      current = current->next;
      delete tmp;
    } else {
      previous = current;
      current = current->next;
    }
  }
}
