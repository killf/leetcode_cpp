#include "utils.h"

/*构造问题*/
class Solution {
public:
  int maximum69Number(int num) {
    stack<int> stack;
    while (num > 0) {
      auto[a, b]=div(num, 10);
      stack.push(b);
      num = a;
    }

    int n = 0, b = true;
    while (!stack.empty()) {
      auto d = stack.top();
      stack.pop();

      if (b && d == 6) {
        d = 9;
        b = false;
      }
      n = n * 10 + d;
    }
    return n;
  }
};