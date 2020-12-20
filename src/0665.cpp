#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>

#include "bitset"

using namespace std;


class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    if (nums.size() <= 2)return true;

    int count = 0, size = nums.size();
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] <= nums[i + 1])continue;

      if (i == 0 || i + 1 == size - 1 ||
          i > 0 && nums[i - 1] <= nums[i + 1] ||
          i + 1 < size - 1 && nums[i] <= nums[i + 2])
        count++;
      else return false;

      if (count > 1)return false;
    }

    return true;
  }
};