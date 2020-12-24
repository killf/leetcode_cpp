#include "utils.h"

/*数学问题*/
class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int n = 0, x = points[0][0], y = points[0][1], xi, yi;
    for (int i = 1; i < points.size(); i++) {
      xi = points[i][0], yi = points[i][1];
      n += max(abs(xi - x), abs(yi - y));
      x = xi;
      y = yi;
    }
    return n;
  }
};
