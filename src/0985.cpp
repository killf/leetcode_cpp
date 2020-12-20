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
  vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] % 2 == 0)sum += A[i];
    }

    vector<int> result;
    for (auto &iter:queries) {
      int val = iter[0], i = iter[1];
      if (A[i] % 2 == 0)sum -= A[i];
      A[i] += val;
      if (A[i] % 2 == 0)sum += A[i];
      result.push_back(sum);
    }

    return result;
  }
};