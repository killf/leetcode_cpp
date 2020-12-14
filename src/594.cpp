#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;


class Solution {
public:
  int findLHS(vector<int> &nums) {
    map<int, int> counters;
    for (auto n:nums) counters[n]++;

    int result = 0;
    for (const auto[n, c]:counters) {
      if (counters.count(n + 1) > 0) {
        result = max(result, c + counters[n + 1]);
      }
    }
    return result;
  }
};

int main() {
  vector<int> v = {1, 3, 2, 2, 5, 2, 3, 7};

  Solution solution;
  solution.findLHS(v);

  return 0;
}