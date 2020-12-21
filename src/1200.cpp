#include "utils.h"

/*排序问题+扫描问题*/
class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> result;
    int min_value = INT32_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
      int d = arr[i + 1] - arr[i];
      if (min_value == d)result.push_back({arr[i], arr[i + 1]});
      else if (min_value > d) {
        result.clear();
        result.push_back({arr[i], arr[i + 1]});
        min_value = d;
      }
    }

    return result;
  }
};