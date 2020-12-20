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
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    int row = nums.size(), col = nums[0].size();
    if (row * col != r * c || row == r && col == c)return nums;

    vector<vector<int>> result(r);

    for (int i = 0, loc = 0; i < r; i++) {
      auto &data = result[i];
      data.resize(c);
      for (int j = 0; j < c; j++, loc++) {
         auto[ii, jj] = div(loc, col);
        data[j] = nums[ii][jj];
      }
    }
    return result;
  }
};