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


/*计数问题*/
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    map<tuple<int, int>, int> map;
    for (auto &v:dominoes) {
      int a = v[0], b = v[1];
      if (a > b)swap(a, b);
      map[{a, b}]++;
    }

    int sums = 0;
    for (auto &[k, v]:map) sums += v * (v - 1) / 2;
    return sums;
  }
};