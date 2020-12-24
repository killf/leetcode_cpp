#include "utils.h"

/*扫描问题*/
class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int size = arr.size(), s4 = size / 4, n = arr[0], c = 1;
    for (int i = 1; i < size; i++) {
      if (arr[i] == n) {
        if (++c > s4)return n;
      } else {
        n = arr[i];
        c = 1;
      }
    }
    return n;
  }
};