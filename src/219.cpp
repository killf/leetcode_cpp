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
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    if (k == 0)return false;

    __gnu_cxx::hash_set<int> hashSet;
    for (int i = 0; i < nums.size(); i++) {
      auto[_, b] = hashSet.insert(nums[i]);
      if (!b)return true;

      if (i >= k)hashSet.erase(nums[i - k]);
    }

    return false;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  int k = 2;

  Solution solution;
  solution.containsNearbyDuplicate(nums, k);
  return 0;
}