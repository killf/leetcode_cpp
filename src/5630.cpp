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
#include <queue>
#include <set>
#include <list>
#include <cstring>
#include <bitset>

using namespace std;


inline int find(vector<int> &nums, int start, int end, int value) {
  for (int i = start; i <= end; i++) {
    if (nums[i] == value)return i;
  }
  return -1;
}

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    if (nums.size() == 1)return nums[0];
    int i = 0, j = 0, sum = 0, max_sum = 0;
    while (j < nums.size()) {
      int index = find(nums, i, j - 1, nums[j]);
      if (index == -1) {
        sum += nums[j];
        max_sum = max(max_sum, sum);
        j++;
      } else {
        for (int k = i; k <= index; k++) sum -= nums[k];
        i = index + 1;

        sum += nums[j];
        max_sum = max(max_sum, sum);
        j++;
      }
    }

    return max_sum;
  }
};

int main() {
  vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
  Solution solution;
  solution.maximumUniqueSubarray(nums);
  return 0;
}