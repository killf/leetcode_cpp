#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int rob(vector<int> nums) {
    if (nums.empty())return 0;
    if (nums.size() == 1)return nums[0];

    int a1 = nums[0], a2 = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      int a3 = max(a1 + nums[i], a2);
      a1 = a2;
      a2 = a3;
    }

    return a2;
  }
};

int main() {
  Solution solution;
  int v = solution.rob({2, 1, 1, 2});
  return 0;
}