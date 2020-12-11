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
  bool canConstruct(string ransomNote, string magazine) {
    int m[26] = {0};
    for (char c : magazine) {
      m[c - 'a']++;
    }

    for (char c:ransomNote) {
      int k = c - 'a';
      if (m[k] <= 0)return false;
      m[k]--;
    }

    return true;
  }
};