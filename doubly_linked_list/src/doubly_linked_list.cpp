#include "doubly_linked_list.h"

DoublyLinkedList::~DoublyLinkedList() { clear(); }

bool DoublyLinkedList::empty() const { return head == nullptr; }

void DoublyLinkedList::clear() {
  while (head != nullptr) {
    auto tmp{head};
    head = head->next;
    delete tmp;
  }
}