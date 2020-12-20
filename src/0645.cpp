#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>

#include "bitset"

using namespace std;


class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int repeat = 0, missing = 0, size = nums.size();

    bitset<10001> set;
    for (auto n:nums) {
      if (set.test(n))repeat = n;
      set.set(n, true);
    }

    for (int i = 1; i <= size; i++) {
      if (!set.test(i)) {
        missing = i;
        break;
      }
    }

    return {repeat, missing};
  }
};
