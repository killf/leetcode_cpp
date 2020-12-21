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


/*递归->动态规划->循环*/
class Solution {
public:
  int tribonacci(int n) {
    int t0 = 0, t1 = 1, t2 = 1;
    if (n == 0)return t0;
    if (n == 1)return t1;
    if (n == 2)return t2;

    for (int i = 3; i <= n; i++) {
      int t = t0 + t1 + t2;
      t0 = t1;
      t1 = t2;
      t2 = t;
    }
    return t2;
  }
};