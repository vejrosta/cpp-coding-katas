#include "linked_list.h"

Elem *LinkedList::getHead() const { return head; }

bool LinkedList::empty() const { return head == nullptr; }

void LinkedList::push_back(int value) {
  if (head == nullptr) {
    head = new Elem{value};
  } else {
    auto current{head};
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Elem{value};
  }
}
