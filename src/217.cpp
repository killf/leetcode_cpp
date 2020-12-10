#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> nums) {
    bool flags[nums.size()];
    int hash_set[nums.size()];
    for (int i = 0; i < nums.size(); i++) flags[i] = false;

    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i], m = n % nums.size();
      while (flags[m]) {
        if (hash_set[m] == n)return true;
        if (++m >= nums.size())m = 0;
      }
      flags[m] = true;
      hash_set[m] = n;
    }

    return false;
  }
};

int main() {
  Solution solution;
  solution.containsDuplicate({1, 2, 3, 1});
  return 0;
}