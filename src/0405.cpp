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

using namespace std;

class Solution {
public:
  string toHex(int num) {
    if (num == 0)return "0";
    unsigned int n = num;

    string s;
    while (n) {
      char c = toHexChar(n & 0x0000000f);
      s.insert(0, 1, c);
      n = n >> 4;
    }

    return s;
  }

  char toHexChar(unsigned int n) {
    if (n < 10)return '0' + n;
    return 'a' + n - 10;
  }
};

int main() {
  Solution solution;
  auto v = solution.toHex(26);
  return 0;
}