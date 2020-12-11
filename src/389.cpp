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
  char findTheDifference(string s, string t) {
    int m[26] = {0};
    for (auto c:s)m[c - 'a']++;

    for (auto c:t) {
      int k = c - 'a';
      if (m[k] == 0)return c;
      m[k]--;
    }
    return 0;
  }
};