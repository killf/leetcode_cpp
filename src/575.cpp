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
  int distributeCandies(vector<int> &candyType) {
    int k = 0, n = candyType.size();
    for (const auto &candy:candyType)if (set(candy))k++;
    return min(n / 2, k);
  }

private:
  bool set(int candy) {
    auto[quot, rem]=div(candy + 100000, 8);
    unsigned char flag = 1 << rem;

    bool b = candies[quot] & flag;
    candies[quot] |= flag;
    return !b;
  }

private:
  unsigned char candies[200000 / 8 + 1] = {0};
};