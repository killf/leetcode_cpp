#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>

using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
  }
};