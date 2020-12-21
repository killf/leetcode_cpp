#include "utils.h"

/*栈问题->成对*/
class Solution {
public:
  int balancedStringSplit(string s) {
    int n = 0;

    char flag;
    stack<char> stack;
    for (auto c:s) {
      if (stack.empty()) {
        flag = c;
        stack.push(flag);
        continue;
      }

      if (c == flag) stack.push(c);
      else {
        stack.pop();
        if (stack.empty())n++;
      }
    }

    return n;
  }
};