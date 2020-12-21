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

/*排序问题*/
class Solution {
public:
  int heightChecker(vector<int> &heights) {
    vector<int> order = heights;
    sort(order.begin(), order.end());

    int n = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != order[i])n++;
    }

    return n;
  }
};