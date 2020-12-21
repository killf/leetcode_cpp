#include "utils.h"


// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  int f(int x, int y) {
    return x + y;
  }
};


/*搜索问题*/
class Solution {
public:
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
    vector<vector<int>> result;
    for (int x = 1; x <= 1000; x++) {
      int y = 1;
      for (; y <= 1000; y++) {
        int r = customfunction.f(x, y);
        if (r == z) {
          result.push_back({x, y});
          break;
        } else if (r > z)break;
      }
      if (y == 1)break;
    }
    return result;
  }
};

int main() {
  CustomFunction customFunction;
  Solution solution;
  solution.findSolution(customFunction, 5);
  return 0;
}