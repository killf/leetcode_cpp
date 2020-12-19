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

using namespace std;

bool compare(string s1, string s2) {
  int p1 = s1.find(' ');
  int p2 = s2.find(' ');

  bool is_digit1 = isdigit(s1[p1 + 1]);
  bool is_digit2 = isdigit(s2[p2 + 1]);

  if (is_digit1) return false;
  if (is_digit2) return true;

  string post1 = s1.substr(p1 + 1), post2 = s2.substr(p2 + 1);
  if (post1 != post2)return post1 < post2;
  else {
    string pre1 = s1.substr(0, p1), pre2 = s2.substr(0, p2);
    return pre1 < pre2;
  }
}

class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), compare);
    return logs;
  }
};

int main() {
  vector<string> logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};

  Solution solution;
  solution.reorderLogFiles(logs);
  return 0;
}