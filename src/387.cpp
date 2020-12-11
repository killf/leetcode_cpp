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

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int m[26] = {0};
    for (auto c :s)m[c - 'a']++;

    for (int i = 0; i < s.size(); i++) {
      if (m[s[i] - 'a'] == 1)return i;
    }
    return -1;
  }
};