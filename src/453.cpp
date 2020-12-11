#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:
  int minMoves(vector<int> &nums) {
    if (nums.size() == 1)return 0;

    long sum = nums[0], min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int n = nums[i];
      sum += n;
      if (n < min)min = n;
    }

    return sum - min * nums.size();
  }
};