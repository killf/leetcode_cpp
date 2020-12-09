#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  inline bool compare(char a, char b) {
    if (a >= 'a')a -= 32;
    if (b >= 'a')b -= 32;
    return a == b;
  }

  bool isPalindrome(string s) {
    if (s.empty())return true;

    int i = 0, j = s.size() - 1;
    while (i <= j) {
      while (i < s.size() && !isalnum(s[i]))i++;
      while (j >= 0 && !isalnum(s[j]))j--;
      if (i >= j)break;

      if (!compare(s[i++], s[j--])) return false;
    }

    return true;
  }
};

int main() {
  Solution solution;
  auto v = solution.isPalindrome("A man, a plan, a canal: Panama");
  return 0;
}