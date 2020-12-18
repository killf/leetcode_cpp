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

using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int> &A) {
    if (A.size() <= 2)return true;

    bool found = false, increase = false;
    for (int i = 0; i < A.size() - 1; i++) {
      if (!found) {
        if (A[i] != A[i + 1]) {
          increase = A[i + 1] > A[i];
          found = true;
          continue;
        }
      } else {
        if (increase) {
          if (A[i] > A[i + 1])return false;
        } else {
          if (A[i] < A[i + 1])return false;
        }
      }
    }
    return true;
  }
};
