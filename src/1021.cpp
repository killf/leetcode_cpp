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

class Solution {
public:
  string removeOuterParentheses(string S) {
    if (S.empty())return "";

    string result;
    stack<char> stack;
    for (char c : S) {
      if (c == '(') {
        if (!stack.empty())result += c;
        stack.push(c);
      } else {
        stack.pop();
        if (!stack.empty())result += c;
      }
    }

    return result;
  }
};

int main() {
  string s;
  s += 'a';

  return 0;
}