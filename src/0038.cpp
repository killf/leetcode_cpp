#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:

  string count(const string &s, int n) {
    if (n <= 0) return s;

    stringstream ss;

    char c = s[0];
    int k = 1;
    for (size_t i = 1; i < s.size(); i++) {
      if (c == s[i]) {
        k++;
      } else {
        ss << k << c;
        c = s[i];
        k = 1;
      }
    }
    ss << k << c;
    return counts(ss.str(), n - 1);
  }

  string countAndSay(int n) {
    return counts("1", n - 1);
  }
};

int main() {
  Solution solution;
  cout << solution.countAndSay(5) << endl;
  return 0;
}