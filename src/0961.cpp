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
  int repeatedNTimes(vector<int> &A) {
    bitset<10000> bs;
    for (auto n:A) {
      if (bs.test(n))return n;
      bs.set(n, true);
    }

    return -1;
  }
};
