#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int sum = 0, m = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      int c = s[i] - 'A' + 1;
      sum += m * c;
      if (i > 0)m *= 26;
    }
    return sum;
  }
};