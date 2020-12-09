#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int v = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (v == nums[i]) count++;
      else if (--count < 0) {
        v = nums[i];
        count = 1;
      }
    }
    return v;
  }
};