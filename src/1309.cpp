#include "utils.h"

/*扫描问题，简单的词法分析器*/
class Solution {
public:
  string freqAlphabets(string s) {
    string d;
    int i = 0, size = s.size();
    while (i < size) {
      if (i + 2 < size && s[i + 2] == '#') {
        d += (char) ((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
        i += 3;
      } else {
        d += (char) (s[i] + 'a' - '1');
        i++;
      }
    }
    return d;
  }
};