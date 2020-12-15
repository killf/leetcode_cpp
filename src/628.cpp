#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>

using namespace std;

class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    int size = nums.size();
    if (size < 6)return product(nums);

    vector<int> ls;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < size; j++) {
        if (nums[i] > nums[j])swap(nums[i], nums[j]);
      }
      ls.push_back(nums[i]);
    }
    for (int i = size - 1; i > size - 4; i--) {
      for (int j = 0; j < i; j++) {
        if (nums[i] < nums[j])swap(nums[i], nums[j]);
      }
      ls.push_back(nums[i]);
    }

    return product(ls);
  }

  int product(vector<int> &nums) {
    int result = nums[0] * nums[1] * nums[2];
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          result = max(result, nums[i] * nums[j] * nums[k]);
        }
      }
    }
    return result;
  }
};