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

using namespace std;


class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for (int n = left; n <= right; n++) {
      int valid = 1, m = n;
      while (m) {
        auto[a, b] = div(m, 10);
        if (b == 0 || n % b != 0) {
          valid = 0;
          break;
        }
        m = a;
      }
      if (valid)result.push_back(n);
    }
    return result;
  }
};