#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;


class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    for (const auto &op:ops) {
      m = min(m, op[0]);
      n = min(n, op[1]);
    }
    return m * n;
  }
};