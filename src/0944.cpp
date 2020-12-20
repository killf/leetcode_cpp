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
#include <set>
#include <list>
#include <cstring>

using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    if (A.size() <= 1)return 0;

    int row = A.size(), col = A[0].size(), count = 0;
    for (int c = 0; c < col; c++) {
      for (int r = 0; r < row - 1; r++) {
        if (A[r][c] > A[r + 1][c]) {
          count++;
          break;
        }
      }
    }

    return count;
  }
};