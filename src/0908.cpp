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
#include <set>

using namespace std;

class Solution {
public:
  int smallestRangeI(vector<int> &A, int K) {
    int max_val = INT32_MIN, min_val = INT32_MAX;
    for (auto n:A) {
      max_val = max(max_val, n);
      min_val = min(min_val, n);
    }
    return max(max_val - min_val - K - K, 0);
  }
};