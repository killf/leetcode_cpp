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

inline int gcd(int a, int b) {
  int c;
  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

/*最大公约数、最小公倍数*/
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    int c = gcd(str1.size(), str2.size());
    string s = str1.substr(0, c);
    if (!is_valid(str1, s) || !is_valid(str2, s))return "";
    return s;
  }

  bool is_valid(string &s1, string &s2) {
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i % s2.size()])return false;
    }
    return true;
  }
};