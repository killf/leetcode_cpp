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
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (auto c :moves) {
      if (c == 'R')x++;
      else if (c == 'L')x--;
      else if (c == 'D')y++;
      else if (c == 'U')y--;
    }
    return x==0 && y == 0;
  }
};