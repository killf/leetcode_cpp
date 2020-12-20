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

class Solution {
public:
  bool isPowerOfFour(int n) {
    return (n > 0) && !(n & (n - 1)) && (n & 0x55555555);
  }
};

int main() {
  long s = 1;
  for (int i = 0; s < INT32_MAX; i++) {
    printf("%d=%ld\n", i, s);
    s = s * 4;
  }
  return 0;
}