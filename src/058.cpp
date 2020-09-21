#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    if (s.size() == 0)return 0;

    int count = 0, state = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (state == 0) {
        if (s[i] != ' ') {
          state = 1;
          count++;
        }
      } else {
        if (s[i] != ' ') count++;
        else break;
      }
    }

    return count;
  }
};

int main() {
  Solution solution;
  cout << solution.lengthOfLastWord("a") << endl;
  return 0;
}