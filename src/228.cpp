#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.empty())return {};

    vector<string> result;

    int i = 0, j = 0;
    while (j < nums.size()) {
      if (j + 1 < nums.size() && (long) nums[j + 1] - nums[j] == 1) j++;
      else {
        stringstream ss;
        if (i == j)ss << nums[i];
        else ss << nums[i] << "->" << nums[j];
        result.push_back(ss.str());
        i = ++j;
      }
    }

    return result;
  }
};

int main() {
  vector<int> x = {-2147483648, -2147483647, 2147483647};
  Solution solution;
  auto v = solution.summaryRanges(x);
  return 0;
}