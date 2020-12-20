#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>

using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int sum = 0, n = nums.size();
    for (int i = 0; i < k; i++)sum += nums[i];

    int result = sum;
    for (int i = k; i < n; i++) {
      sum += nums[i] - nums[i - k];
      if (sum > result)result = sum;
    }
    return (double) result / k;
  }
};

int main() {
  vector<int> nums = {0, 4, 0, 3, 2};
  int k = 1;

  Solution solution;
  auto result = solution.findMaxAverage(nums, k);
  return 0;
}