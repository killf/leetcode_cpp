#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.empty())return true;

    char m1[256] = {0}, m2[256] = {0};
    for (int i = 0; i < s.size(); i++) {
      char a = s[i], b = t[i];
      if (m1[a] == 0 && m2[b] == 0) {
        m1[a] = b;
        m2[b] = a;
      } else if (m1[a] != b || m2[b] != a)return false;
    }

    return true;
  }
};

int main() {
  Solution solution;
  auto v = solution.isIsomorphic("ab", "aa");
  return 0;
}