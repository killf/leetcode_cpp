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
#include <bitset>
#include <set>

using namespace std;

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> nums;
    for (int i = 0; i < S.size(); i++)if (S[i] == C)nums.push_back(i);
    if (nums.empty())return {};

    vector<int> result;
    for (int n = 0; n < nums[0]; n++)result.push_back(nums[0] - n);
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int n = nums[i]; n < nums[i + 1]; n++) {
        result.push_back(min(n - nums[i], nums[i + 1] - n));
      }
    }
    result.push_back(0);
    for (int n = nums[nums.size() - 1] + 1; n < S.size(); n++)result.push_back(n - nums[nums.size() - 1]);

    return result;
  }
};

int main() {
  string S = "lovea";
  char C = 'e';
  Solution solution;
  solution.shortestToChar(S, C);
  return 0;
}