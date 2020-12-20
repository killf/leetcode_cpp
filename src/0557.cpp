#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int i = 0, j = 0;
    while (j < s.size()) {
      while (i < s.size() && s[i] == ' ') j = ++i;
      if (i >= s.size())break;

      while (j < s.size() && s[j] != ' ') j++;

      reverse(s, i, j - i);
      i = j;
    }

    return s;
  }

  void reverse(string &s, int start, int num) {
    if (start >= s.size() - 1)return;
    for (int i = 0; i < num / 2; i++)swap(s[start + i], s[start + num - i - 1]);
  }
};