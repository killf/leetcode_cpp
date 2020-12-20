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
  vector<int> powerfulIntegers(int x, int y, int bound) {
    vector<int> xs = {1}, ys = {1};
    if (x > 1) for (int i = x; i < bound; i *= x)xs.push_back(i);
    if (y > 1) for (int i = y; i < bound; i *= y)ys.push_back(i);

    set<int> result;
    for (int i = 0; i < xs.size(); i++) {
      for (int j = 0; j < ys.size(); j++) {
        int sum = xs[i] + ys[j];
        if (sum <= bound) result.insert(sum);
      }
    }

    return vector(result.begin(), result.end());
  }
};