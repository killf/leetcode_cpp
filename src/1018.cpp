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
  vector<bool> prefixesDivBy5(vector<int> &A) {
    vector<bool> result;
    int n = 0;
    for (int i = 0; i < A.size(); i++) {
      n = (n * 2 + A[i]) % 5;
      result.push_back(n == 0);
    }
    return result;
  }
};