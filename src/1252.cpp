#include "utils.h"

/*计数问题*/
class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>> &indices) {
    int rows[n], cols[m];
    memset(rows, 0, sizeof(int) * n);
    memset(cols, 0, sizeof(int) * m);

    for (auto &pos:indices) {
      rows[pos[0]]++;
      cols[pos[1]]++;
    }

    int r = 0, c = 0;
    for (int i = 0; i < n; i++)if (rows[i] & 1)r++;
    for (int i = 0; i < m; i++)if (cols[i] & 1)c++;

    return r * m + c * n - r * c * 2;
  }
};

int main() {
  int a[10];
  int b = size(a);

  return 0;
}