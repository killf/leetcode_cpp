#include "utils.h"

/*构造问题，只要有一个合理的答案就行*/
class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> result;
    for (int i = 1; i <= n / 2; i++) {
      result.emplace_back(i);
      result.emplace_back(-i);
    }
    if (n % 2 == 1)result.emplace_back(0);
    return result;
  }
};