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
  int surfaceArea(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid.size(), sum = 0;

    for (int r = 0; r < row; r++) {
      sum += grid[r][0] + grid[r][col - 1];
      for (int c = 0; c < col - 1; c++) {
        sum += abs(grid[r][c] - grid[r][c + 1]);
        if (grid[r][c] > 0) sum += 1;
      }
      if (grid[r][col - 1] > 0) sum += 1;
    }

    for (int c = 0; c < col; c++) {
      sum += grid[0][c] + grid[row - 1][c];
      for (int r = 0; r < row - 1; r++) {
        sum += abs(grid[r][c] - grid[r + 1][c]);
        if (grid[r][c] > 0) sum += 1;
      }
      if (grid[row - 1][c] > 0) sum += 1;
    }

    return sum;
  }
};