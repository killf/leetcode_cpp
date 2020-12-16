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

bool is_vowel(char c) {
  c = (char) tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
  string toGoatLatin(string S) {
    stringstream ss;
    int count = 0, status = 0;
    bool vowel = false;
    char first_char;
    for (int i = 0; i <= S.size();) {
      auto c = S[i];
      if (c == 0)status = 2;

      if (status == 0) {
        vowel = is_vowel(c);
        if (vowel)ss << c; else first_char = c;
        status = 1;
        i++;
      } else if (status == 1) {
        if (c == ' ') {
          status = 2;
          continue;
        }

        ss << c;
        i++;
      } else if (status == 2) {
        count++;
        if (!vowel)ss << first_char;
        ss << "ma";
        for (int j = 0; j < count; j++)ss << 'a';
        ss << c;

        i++;
        status = 3;
      } else if (status == 3) {
        if (c != ' ') {
          status = 0;
          continue;
        }

        ss << c;
        i++;
      }
    }

    return ss.str();
  }
};

int main() {
  Solution solution;
  auto r = solution.toGoatLatin("I speak Goat Latin");
  return 0;
}