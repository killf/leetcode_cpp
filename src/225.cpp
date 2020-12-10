#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>

using namespace std;

class MyStack {
public:
  explicit MyStack() = default;

  void push(int x) {
    queue.push(x);
    for (int i = 0; i < queue.size() - 1; i++) {
      queue.push(queue.front());
      queue.pop();
    }
  }

  int pop() {
    int n = queue.front();
    queue.pop();
    return n;
  }

  int top() {
    return queue.front();
  }

  bool empty() {
    return queue.empty();
  }

private:
  queue<int> queue;
};
