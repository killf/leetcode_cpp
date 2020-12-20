#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) : sums(nums.size()) {
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      sums[i] = sum;
    }
  }

  int sumRange(int i, int j) {
    if (i == 0)return sums[j];
    return (int)(sums[j] - sums[i - 1]);
  }

private:
  vector<long> sums;
};