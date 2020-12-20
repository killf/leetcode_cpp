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
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:
  int arrangeCoins(int n) {
    if (n <= 0)return 0;
    return sqrt(2 * (long)n + 0.25) - 0.5;
  }
};