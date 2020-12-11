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
  string reverseVowels(string s) {
    if (s.size() <= 1)return s;

    bool m[128] = {false};
    m['a'] = m['A'] = m['e'] = m['E'] = m['i'] = m['I'] = m['o'] = m['O'] = m['u'] = m['U'] = true;

    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!m[s[i]]) i++;
      else if (!m[s[j]])j--;
      else {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }

    return s;
  }
};

int main() {
  string s = "Hello,world\n";
  s[0] = 'A';
  swap(s[0], s[1]);

  cout << s;
  return 0;
}