#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int v = 0;
    while (n >= 5) {
      n = n / 5;
      v += n;
    }
    return v;
  }
};