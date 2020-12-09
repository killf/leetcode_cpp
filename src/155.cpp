#include <iostream>
#include <string>
#include <vector>

using namespace std;


class MinStack {
private:
  struct Node {
    Node *next;
    int value, min_value;
  };

  Node *ptr;

public:
  MinStack() : ptr(nullptr) {}

  void push(int x) {
    auto *node = new Node();
    node->value = x;

    if (!ptr) {
      node->min_value = x;
      node->next = nullptr;
      ptr = node;
    } else {
      node->min_value = min(x, ptr->min_value);
      node->next = ptr;
      ptr = node;
    }
  }

  void pop() {
    if (ptr)ptr = ptr->next;
  }

  int top() {
    return ptr->value;
  }

  int getMin() {
    return ptr->min_value;
  }
};