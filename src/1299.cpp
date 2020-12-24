#include "utils.h"

/*扫描问题，选择访问过的最大元素*/
class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int size = arr.size(), max_val = -1;
    vector<int> result(size);
    for (int i = size - 1; i >= 0; i--) {
      max_val = max(arr[i], result[i] = max_val);
    }
    return result;
  }
};