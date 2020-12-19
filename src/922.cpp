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
  vector<int> sortArrayByParityII(vector<int> &A) {
    vector<int> result(A.size());
    int size = A.size(), i = 0, j = 1;
    for (auto n:A) {
      if (n & 1) {
        result[j] = n;
        j += 2;
      } else {
        result[i] = n;
        i += 2;
      }
    }
    return result;
  }
};