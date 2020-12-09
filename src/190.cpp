#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0, a = 1, b = 1 << 31;

    for (int i = 0; i < 32; i++) {
      if (n & a)m |= b;
      a <<= 1;
      b >>= 1;
    }
    return m;
  }
};