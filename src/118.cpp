#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0)return result;

    result.push_back({1});
    if (numRows == 1)return result;

    result.push_back({1, 1});
    if (numRows == 2)return result;

    for (int i = 2; i < numRows; i++) {
      vector<int> v = {1};
      auto &last = result.back();
      for (int j = 0; j < i - 1; j++) {
        v.push_back(last[j] + last[j + 1]);
      }
      result.push_back(v);
    }

    return result;
  }
};