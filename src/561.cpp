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
  int arrayPairSum(vector<int> &nums) {
    int hash[20001] = {0};
    int *count = hash + 10000;
    for (const auto &n:nums)count[n]++;

    int sum = 0, d = 0;
    for (int i = -10000; i <= 10000; i++) {
      sum += (count[i] + 1 - d) / 2 * i;
      d = (2 + count[i] - d) % 2;
    }
    return sum;
  }
};