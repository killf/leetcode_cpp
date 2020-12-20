#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int i = 0, j = 0, count = 0;
    while (j < nums.size()) {
      if (nums[i] == 0) j = ++i;
      else if (nums[j++] == 1) count = max(count, j - i);
      else i = j;
    }

    return count;
  }
};

