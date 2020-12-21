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

/*广度优先搜索，注意剪枝*/
class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> result;

    bitset<10000> flags;
    queue<tuple<int, int>> queue;
    queue.emplace(r0, c0);
    while (!queue.empty()) {
      auto[r, c]= queue.front();
      queue.pop();

      if (flags.test(r * C + c))continue;
      result.push_back({r, c});
      flags.set(r * C + c, true);

      if (r > 0 && !flags.test((r - 1) * C + c))queue.emplace(r - 1, c);
      if (c > 0 && !flags.test(r * C + c - 1))queue.emplace(r, c - 1);
      if (r < R - 1 && !flags.test((r + 1) * C + c))queue.emplace(r + 1, c);
      if (c < C - 1 && !flags.test(r * C + c + 1))queue.emplace(r, c + 1);
    }

    return result;
  }
};