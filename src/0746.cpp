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

using namespace std;


class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int size = cost.size();
    int a = cost[size - 2], b = cost[size - 1];
    for (int i = 3; i <= size; i++) {
      int c = min(a, b) + cost[size - i];
      b = a;
      a = c;
    }
    return min(a, b);
  }
};

int main() {
  vector<int> cost = {10, 15, 20};
  Solution solution;
  auto ret = solution.minCostClimbingStairs(cost);
  return 0;
}