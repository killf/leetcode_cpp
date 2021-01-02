#include "utils.h"

/*构造问题*/
class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    int a = 0, b = n, c = n, d = 1;
    while (n > 0) {
      auto[i, j]= div(n, 10);
      if (j == 1 && i > 0) {
        a += 2 * d;
        b -= 2 * d;
      } else {
        a += d;
        b -= d;
      }

      d *= 10;
      n = b / d;
    }

    return {a, b};
  }
};