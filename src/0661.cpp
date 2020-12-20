#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>

#include "bitset"

using namespace std;


class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    int row = M.size(), col = M[0].size();

    vector<vector<int>> result(row);
    for (int r = 0; r < row; r++) {
      result[r].resize(col);
      for (int c = 0; c < col; c++) {
        int sum = 0, count = 0;
        for (int i = max(r - 1, 0); i <= min(r + 1, row - 1); i++) {
          for (int j = max(c - 1, 0); j <= min(c + 1, col - 1); j++) {
            sum += M[i][j];
            count++;
          }
        }
        result[r][c] = sum / count;
      }
    }
    return result;
  }
};