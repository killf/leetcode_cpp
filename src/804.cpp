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
#include <bitset>
#include <set>

using namespace std;

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    set<string> set;

    stringstream ss;
    for (const auto &w:words) {
      ss.str("");
      for (auto c:w)ss << morse[c - 'a'];
      set.insert(ss.str());
    }

    return set.size();
  }

private:
  vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                          "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
  };
};