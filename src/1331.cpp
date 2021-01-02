#include "utils.h"

/*排序问题*/
class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    multimap<int, int> mm;
    for (int i = 0; i < arr.size(); i++) mm.emplace(arr[i], i);

    vector<int> result(arr.size());
    int last_val, last_index, is_first = true;
    for (auto[k, v]:mm) {
      if (is_first) {
        is_first = false;
        last_val = k;
        result[v] = last_index = 1;
      } else if (last_val == k) {
        result[v] = last_index;
      } else {
        last_val = k;
        result[v] = ++last_index;
      }
    }
    return result;
  }
};

int main() {
  vector<int> ls = {3, 2, 5, 1};
  stable_sort(ls.rbegin(), ls.rend());
  return 0;
}