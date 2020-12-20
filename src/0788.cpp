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

int rotates[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

inline bool is_valid(int n) {
  bool is_same = true;
  while (n > 0) {
    auto[a, b]=div(n, 10);
    int r = rotates[b];
    if (r < 0)return false;
    if (r != b)is_same = false;
    n = a;
  }
  return !is_same;
}


class Solution {
public:
  int rotatedDigits(int N) {
    int result = 0;
    for (int i = 2; i <= N; i++)if (is_valid(i))result++;
    return result;
  }
};