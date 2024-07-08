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

void DoublyLinkedList::remove(int value) {
  if (head == nullptr) {
    return;
  }

  if (head->data == value) {
    auto tmp{head};
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete tmp;
    return;
  }

  auto current{head};
  while (current->next != nullptr) {
    if (current->next->data == value) {
      auto tmp{current->next};
      current->next = current->next->next;
      if (current->next != nullptr) {
        current->next->prev = current;
      } else {
        tail = current;
      }
      delete tmp;
      return;
    }
    current = current->next;
  }
}

void DoublyLinkedList::removeByIndex(int index) {
  if (head == nullptr) {
    return;
  }

  if (index == 0) {
    auto tmp{head};
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
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
  current->next = current->next->next;
  if (current->next != nullptr) {
    current->next->prev = current;
  } else {
    tail = current;
  }
  delete tmp;
}

void DoublyLinkedList::clear() {
  while (head != nullptr) {
    auto tmp{head};
    head = head->next;
    delete tmp;
  }
}