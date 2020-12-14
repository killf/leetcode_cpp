#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>

using namespace std;

class Solution {
public:
  Solution() {
    string r1 = "qwertyuiop", r2 = "asdfghjkl", r3 = "zxcvbnm";
    for (auto c:r1)rows[c - 'a'] = 1;
    for (auto c:r2)rows[c - 'a'] = 2;
    for (auto c:r3)rows[c - 'a'] = 3;
  }

  vector<string> findWords(vector<string> &words) {
    vector<string> result;
    for (const auto &w:words) {
      if (w.size() <= 1) {
        result.push_back(w);
        continue;
      }

      bool is_matched = true;
      char r = rows[tolower(w[0]) - 'a'];
      for (int i = 1; i < w.size(); i++) {
        if (rows[tolower(w[i]) - 'a'] != r) {
          is_matched = false;
          break;
        }
      }

      if (is_matched)result.push_back(w);
    }
    return result;
  }

private:
  char rows[26];
};