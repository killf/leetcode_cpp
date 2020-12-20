#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int v = 0;
    while (n) {
      v++;
      n &= n - 1;
    }
    return v;
  }
};