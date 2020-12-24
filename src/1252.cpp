#include "utils.h"

/*计数问题*/
class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>> &indices) {
    int data[100] = {};
    int *rows = data, *cols = data + 50;

    int r = 0, c = 0;
    for (auto &pos:indices) {
      if (++rows[pos[0]] & 1)r++; else r--;
      if (++cols[pos[1]] & 1)c++; else c--;
    }

    return r * m + c * n - r * c * 2;
  }
};

int main() {
  int a[10];
  int b = size(a);

  return 0;
}