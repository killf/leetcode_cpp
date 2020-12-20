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
#include <deque>

using namespace std;


class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
    int size = nums.size();

    deque<tuple<int, int>> deque;
    deque.emplace_back(0, nums[0]);
    for (int i = 1; i < size; i++) {
      while (get<0>(deque.front()) < i - k)deque.pop_front();
      auto f = get<1>(deque.front()) + nums[i];

      while (!deque.empty() && get<1>(deque.back()) < f) deque.pop_back();
      deque.emplace_back(i, f);
    }

    return get<1>(deque.back());
  }
};

int main() {
  vector<int> nums = {10, -5, -2, 4, 0, 3};
  int k = 3;

  Solution solution;
  auto ret = solution.maxResult(nums, k);
  return 0;
}