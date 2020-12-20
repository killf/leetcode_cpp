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
  int largestPerimeter(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = A.size() - 1; i >= 2; i--) {
      if (A[i] < A[i - 1] + A[i - 2])return A[i] + A[i - 1] + A[i - 2];
    }
    return 0;
  }
};