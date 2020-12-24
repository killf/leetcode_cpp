#include "utils.h"

/*数学问题*/
class Solution {
public:
  int subtractProductAndSum(int n) {
    int a = 1, b = 0;
    while (n > 0) {
      auto[c, d]=div(n, 10);
      a *= d;
      b += d;
      n = c;
    }
    return a - b;
  }
};