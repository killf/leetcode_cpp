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
  int projectionArea(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid[0].size(), s = 0;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] > 0)s++;
      }
    }

    for (int i = 0; i < row; i++) {
      int m = 0;
      for (int j = 0; j < col; j++) {
        m = max(m, grid[i][j]);
      }
      s += m;
    }

    for (int j = 0; j < col; j++) {
      int m = 0;
      for (int i = 0; i < col; i++) {
        m = max(m, grid[i][j]);
      }
      s += m;
    }

    return s;
  }
};