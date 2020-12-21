#include "utils.h"

/*计数问题->奇偶性*/
class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    size_t n = 0;
    for (auto p:position)if (p & 1)n++;
    return min(n, position.size() - n);
  }
};