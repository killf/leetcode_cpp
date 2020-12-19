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

using namespace std;

class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    set<string> set;
    for (auto &email:emails)set.insert(process(email));
    return set.size();
  }

  string process(string &email) {
    stringstream ss;
    int status = 0;
    for (int i = 0; i < email.size(); i++) {
      char c = email[i];
      switch (status) {
        case 0:
          if (c == '.')continue;
          if (c == '+') {
            status = 1;
            continue;
          }
          if (c == '@') {
            ss << c;
            status = 2;
            continue;
          }

          ss << c;
          break;
        case 1:
          if (c == '@') {
            ss << c;
            status = 2;
            continue;
          }
          break;
        case 2:
          ss << c;
          break;
      }
    }
    return ss.str();
  }
};

int main() {
  vector<string> emails = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};
  Solution solution;
  solution.numUniqueEmails(emails);
  return 0;
}