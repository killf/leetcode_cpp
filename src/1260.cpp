#include "utils.h"

/*下标计算*/
class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int row = grid.size(), col = grid[0].size();

    vector<vector<int>> result(row);
    for (auto &iter:result)iter.resize(col);

    int total = row * col;
    for (int r1 = 0; r1 < row; r1++) {
      for (int c1 = 0; c1 < col; c1++) {
        int index = (r1 * col + c1 + k) % total;
        int r2 = index / col;
        int c2 = index % col;
        result[r2][c2] = grid[r1][c1];
      }
    }
    return result;
  }
};

