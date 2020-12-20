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
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> result(nums.size());

    int size = nums.size(), i = 0, j = size - 1, n = size - 1;
    while (i <= j) {
      if (abs(nums[i]) < (nums[j])) {
        result[n--] = nums[j] * nums[j];
        j--;
      } else {
        result[n--] = nums[i] * nums[i];
        i++;
      }
    }

    return result;
  }
};