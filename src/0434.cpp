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
#include <iomanip>

using namespace std;

class Solution {
public:
  int countSegments(string s) {
    int num = 0;

    bool in_word = false;
    for (int i = 0; i < s.size(); i++) {
      if (in_word) {
        if (!is_valid_char(s[i])) {
          num++;
          in_word = false;
        }
      } else {
        if (is_valid_char(s[i]))in_word = true;
      }
    }
    if (in_word)num++;

    return num;
  }

  bool is_valid_char(char c) {
    return c!=' ';
  }
};