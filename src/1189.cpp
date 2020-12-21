#include "utils.h"

/*计数问题*/
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int dict[26] = {};
    for (auto c:text)dict[c - 'a']++;

    int n = dict[0];
    for (auto &[c, d]:counts) {
      n = min(n, dict[c - 'a'] / d);
    }
    return n;
  }

private:
  map<char, int> counts = {{'a', 1},
                           {'b', 1},
                           {'l', 2},
                           {'o', 2},
                           {'n', 1}};
};