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
#include <bitset>

using namespace std;

vector<string> split(const string &s, char c) {
  vector<string> result;

  string t;
  for (auto k :s) {
    if (k == c) {
      if (!t.empty()) {
        result.push_back(t);
        t.clear();
      }
    } else t += k;
  }
  if (!t.empty())result.push_back(t);

  return result;
}

/*线性扫描问题*/
class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> ss = split(text, ' '), result;

    for (int i = 0; i < ss.size() - 2; i++) {
      if (ss[i] == first && ss[i + 1] == second) {
        result.push_back(ss[i + 2]);
      }
    }

    return result;
  }
};

int main() {
  auto v = split(string("alice is a good girl she is a good student"), ' ');

  return 0;
}