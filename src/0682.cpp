#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
  int calPoints(vector<string> &ops) {
    vector<int> stack;
    for (const auto &op:ops) {
      if (op == "C") stack.pop_back();
      else if (op == "D")stack.push_back(stack[stack.size() - 1] * 2);
      else if (op == "+") stack.push_back(stack[stack.size() - 1] + stack[stack.size() - 2]);
      else stack.push_back(atoi(op.c_str()));
    }

    int sum = 0;
    for (auto n:stack)sum += n;
    return sum;
  }
};

int main() {
  vector<string> ops = {"5", "2", "C", "D", "+"};
  Solution solution;
  solution.calPoints(ops);
  return 0;
}