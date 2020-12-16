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
  int pivotIndex(vector<int> &nums) {
    if (nums.empty())return -1;

    long sum = 0;
    for (auto n:nums)sum += n;

    long left = 0, right = sum;
    for (int i = 0; i < nums.size(); i++) {
      if (i >= 1) left += nums[i - 1];
      right -= nums[i];
      if (left == right)return i;
    }

    return -1;
  }
};