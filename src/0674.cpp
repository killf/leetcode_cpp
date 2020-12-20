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
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty())return 0;

    int result = 1, count = 1, size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] < nums[i + 1]) count++;
      else {
        result = max(result, count);
        count = 1;
      }
    }

    return max(result, count);
  }
};