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
  int search(vector<int> &nums, int target) {
    int a = 0, b = nums.size() - 1, c, n;
    while (a <= b) {
      c = (a + b) / 2;
      n = target - nums[c];
      if (!n)return c;
      if (n > 0)a = c + 1; else b = c - 1;
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  Solution solution;
  solution.search(nums, 2);
  return 0;
}