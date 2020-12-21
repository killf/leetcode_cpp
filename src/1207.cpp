#include "utils.h"

/*计数问题->查表法加速*/
class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    int d1[2001] = {};
    for (int n:arr)d1[n + 1000]++;

    bitset<1000> d2;
    for (int i = 0; i < 2001; i++) {
      if (d1[i] > 0) {
        if (d2.test(d1[i]))return false;
        d2.set(d1[i]);
      }
    }

    return true;
  }
};