#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int &n = nums[i], loc = i + 1;
      while (n != loc && n != -1) {
        if (n == nums[n - 1]) {
          n = -1;
          break;
        } else {
          swap(n, nums[n - 1]);
        }
      }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == -1)result.push_back(i + 1);
    }
    return result;
  }
};

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution solution;
  auto v = solution.findDisappearedNumbers(nums);
  return 0;
}