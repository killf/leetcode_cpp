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

using namespace std;

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    if (words.size() <= 1)return true;

    int order_set[26] = {};
    for (int i = 0; i < order.size(); i++)order_set[order[i] - 'a'] = i;

    for (int i = 0; i < words.size() - 1; i++) {
      string &s1 = words[i], &s2 = words[i + 1];

      bool is_matched = false;
      for (int j = 0; j < min(s1.size(), s2.size()); j++) {
        if (order_set[s1[j] - 'a'] < order_set[s2[j] - 'a']) {
          is_matched = true;
          break;
        }
        if (order_set[s1[j] - 'a'] > order_set[s2[j] - 'a'])return false;
      }

      if (!is_matched && s1.size() > s2.size())return false;
    }

    return true;
  }
};
