#include "utils.h"

/*素数问题+排列组合问题*/
class Solution {
public:
  int numPrimeArrangements(int n) {
    int m = 0;
    vector<bool> nums(n + 1, true);

    for (int i = 2; i <= n; i++) {
      if (!nums[i])continue;
      for (int p = i + i; p <= n; p += i) {
        nums[p] = false;
      }
      m++;
    }

    long sum = 1;
    for (int i = 1; i <= m; i++) {
      sum *= i;
      sum %= 1000000007;
    }
    for (int i = 1; i <= n - m; i++) {
      sum *= i;
      sum %= 1000000007;
    }
    return sum;
  }
};