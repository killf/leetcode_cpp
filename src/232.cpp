#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class MyQueue {
public:
  explicit MyQueue() = default;

  void push(int x) {
    while (!p1->empty()) {
      p2->push(p1->top());
      p1->pop();
    }

    p1->push(x);

    while (!p2->empty()) {
      p1->push(p2->top());
      p2->pop();
    }
  }

  int pop() {
    int v = p1->top();
    p1->pop();
    return v;
  }

  int peek() {
    return p1->top();
  }

  bool empty() {
    return p1->empty();
  }

private:
  stack<int> stack1;
  stack<int> stack2;
  stack<int> *p1 = &stack1;
  stack<int> *p2 = &stack2;
};
