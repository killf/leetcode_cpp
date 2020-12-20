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
#include <bitset>

using namespace std;

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<vector<bool>> A(N);
    for (auto &row:A) row.resize(N, false);
    for (auto &v:trust)A[v[0] - 1][v[1] - 1] = true;

    for (int i = 0; i < N; i++) {
      bool cond = true;
      for (int j = 0; j < N; j++) {
        if (i == j)continue;
        if (!A[j][i] || A[i][j]) {
          cond = false;
          break;
        }
      }
      if (cond)return i + 1;
    }
    return -1;
  }
};