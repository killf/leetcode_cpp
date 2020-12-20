#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> nums) {
    int v = 0;
    for (auto iter:nums)v ^= iter;
    return v;
  }
};

int main() {
  Solution solution;
  auto v = solution.singleNumber({2, 2, 1});
  return 0;
}