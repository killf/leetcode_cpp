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
  bool canThreePartsEqualSum(vector<int> &A) {
    vector<long> sums;
    long sum = 0;
    for (int i = 0; i < A.size(); i++) {
      sum += A[i];
      sums.push_back(sum);
    }
    if (sum % 3 != 0)return false;

    int i = 0, t = sum / 3;
    for (; i < sums.size(); i++) if (sums[i] == t) break;
    if (i >= sums.size())return false;

    i++;
    t += t;
    for (; i < sums.size(); i++) if (sums[i] == t) break;
    return i < sums.size() - 1;
  }
};