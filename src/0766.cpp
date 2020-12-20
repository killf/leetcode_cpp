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

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    for (int r = row - 2; r >= 0; r--) {
      for (int c = 0; c < col - 1; c++) {
        if (matrix[r][c] != matrix[r + 1][c + 1])return false;
      }
    }
    return true;
  }
};