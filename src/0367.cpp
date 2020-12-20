#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num < 0)return false;
    if (num == 0 || num == 1)return true;

    for (long i = 2; i < num; i++) {
      long v = i * i;
      if (v == num)return true;
      if (v > num)return false;
    }

    return false;
  }
};