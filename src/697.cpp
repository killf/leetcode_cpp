#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    vector<int> first(50000, -1), last(50000, -1);
    int counter[50000] = {}, max_count = -1;
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      if (first[n] == -1)first[n] = i;
      last[n] = i;

      int count = ++counter[n];
      max_count = max(max_count, count);
    }

    int result = INT32_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      if (counter[n] < max_count)continue;
      result = min(result, last[n] - first[n] + 1);
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 3, 1};
  Solution solution;
  auto result = solution.findShortestSubArray(nums);
  return 0;
}