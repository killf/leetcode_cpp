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

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int m[128] = {};
    for (auto c:J)m[c]++;

    int result = 0;
    for (auto c:S)if (m[c] > 0)result++;

    return result;
  }
};