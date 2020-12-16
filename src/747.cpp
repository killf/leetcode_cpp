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

using namespace std;


class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int result = 0, first_val = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > first_val) {
        first_val = nums[i];
        result = i;
      }
    }

    int second = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (i == result)continue;
      if (second == -1 || nums[i] > second)second = nums[i];
    }

    return first_val >= second * 2 ? result : -1;
  }
};