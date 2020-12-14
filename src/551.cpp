#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
  bool checkRecord(string s) {
    int A = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A' && ++A > 1) return false;
      if (i + 2 < s.size() && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')return false;
    }
    return true;
  }
};