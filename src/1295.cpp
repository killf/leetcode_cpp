#include "utils.h"

/*数学问题*/
class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int n = 0;
    for (auto x:nums)if (is_even(x))n++;
    return n;
  }

  inline bool is_even(int n) {
    return 9 < n && n < 100 || 999 < n && n < 10000 || 99999 < n && n < 1000000;
  }
};