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
  double largestTriangleArea(vector<vector<int>> &points) {
    int size = points.size(), max_area = 0;
    for (int i = 0; i < size; i++) {
      int xi = points[i][0], yi = points[i][1];
      for (int j = i + 1; j < size; j++) {
        int x1 = points[j][0] - xi, y1 = points[j][1] - yi;
        for (int k = j + 1; k < size; k++) {
          int x2 = points[k][0] - xi, y2 = points[k][1] - yi;

          int area = abs(x1 * y2 - x2 * y1);
          if (area > max_area)max_area = area;
        }
      }
    }
    return max_area / 2.0;
  }
};