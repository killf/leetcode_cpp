#include "utils.h"

/*数学问题->扫描问题*/
class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int x1 = coordinates[1][0], y1 = coordinates[1][1];
    int dx = x1 - x0, dy = y1 - y0;

    for (int i = 2; i < coordinates.size(); i++) {
      int x2 = coordinates[i][0], y2 = coordinates[i][1];
      if (dy * (x2 - x0) != (y2 - y0) * dx)return false;
    }
    return true;
  }
};