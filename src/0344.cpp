#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    if (s.size() <= 1)return;

    for (int i = 0; i < s.size() / 2; i++) {
      swap(s[i], s[s.size() - i - 1]);
    }
  }
};