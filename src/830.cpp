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
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> result;
    int i = 0, j;
    for (; i < s.size();) {
      for (j = i + 1; j < s.size(); j++) {
        if (s[i] != s[j])break;
      }

      if (j - i >= 3)result.push_back({i, j - 1});
      i = j;
    }

    return result;
  }
};