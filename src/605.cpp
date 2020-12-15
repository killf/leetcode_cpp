#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int sum = 0, m = 0, size = flowerbed.size();

    vector<int> nums;
    for (int i = 0, j = 0; j < size; i = ++j) {
      while (i < size && flowerbed[i] == 1)j = ++i;
      while (j < size && flowerbed[j] == 0)j++;
      int d = j - i;
      if (d > m)m = d;
      nums.push_back(d);
    }

    if (flowerbed[0] == 0)nums[0] += 1;
    if (flowerbed[size - 1] == 0)nums[nums.size() - 1] += 1;

    vector<int> flowers(max(m, 3) + 3);
    flowers[0] = flowers[1] = flowers[2] = 0;
    for (int i = 3; i < flowers.size(); i++)flowers[i] = flowers[i - 2] + 1;

    for (auto c:nums)if ((sum += flowers[c]) >= n)return true;
    return false;
  }
};

int main() {
  vector<int> flowerbed = {0, 0, 0};
  int n = 1;

  Solution solution;
  auto result = solution.canPlaceFlowers(flowerbed, n);

  return 0;
}