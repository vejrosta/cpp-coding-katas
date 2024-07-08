#include "doubly_linked_list.h"

DoublyLinkedList::~DoublyLinkedList() { clear(); }

Node *DoublyLinkedList::getHead() const { return head; }
Node *DoublyLinkedList::getTail() const { return tail; }

bool DoublyLinkedList::empty() const { return head == nullptr; }

void DoublyLinkedList::push_back(int value) {
  if (head == nullptr) {
    head = new Node{value};
    tail = head;
  } else {
    tail->next = new Node{value};
    tail->next->prev = tail;
    tail = tail->next;
  }
}

void DoublyLinkedList::push_front(int value) {
  if (head == nullptr) {
    head = new Node{value};
    tail = head;
  } else {
    head->prev = new Node{value};
    head->prev->next = head;
    head = head->prev;
  }
}

void DoublyLinkedList::clear() {
  while (head != nullptr) {
    auto tmp{head};
    head = head->next;
    delete tmp;
  }
}