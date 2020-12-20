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
  int largestSumAfterKNegations(vector<int> &A, int K) {
    sort(A.begin(), A.end());

    int neg = 0;
    for (auto n :A)if (n < 0)neg++;

    if (K <= neg) {
      for (int i = 0; i < K; i++)A[i] = -A[i];
    } else {
      for (int i = 0; i < neg; i++)A[i] = -A[i];
      if ((K - neg) % 2 == 1) {
        if (neg == 0 || A[neg] < A[neg - 1]) A[neg] = -A[neg];
        else A[neg - 1] = -A[neg - 1];
      }
    }

    int sum = 0;
    for (auto n:A)sum += n;
    return sum;
  }
};