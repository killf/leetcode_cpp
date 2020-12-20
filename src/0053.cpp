#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // f(i) = max{f(i-1)+a[i],a[i]}
    int sum = 0, max_sum = nums[0];
    for (size_t i = 0; i < nums.size(); i++) {
      sum = max(sum + nums[i], nums[i]);
      if (sum > max_sum)max_sum = sum;
    }
    return max_sum;
  }
};


int main() {
  Solution solution;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << solution.maxSubArray(nums) << endl;
  return 0;
}