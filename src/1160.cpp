#include "utils.h"

/*计数问题*/
class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    vector<int> dict(26);
    for (auto c:chars)dict[c - 'a']++;

    int sum = 0;
    for (auto &s:words) {
      vector<int> m = dict;
      bool valid = true;
      for (auto c:s) {
        if (--m[c - 'a'] < 0) {
          valid = false;
          break;
        }
      }

      if (valid) sum += s.size();
    }

    return sum;
  }
};