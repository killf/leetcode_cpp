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

using namespace std;


class Solution {
public:
  bool validPalindrome(string s) {
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
      if (s[i] != s[size - i - 1])return isPalindrome(s, i + 1, size - i - 1) || isPalindrome(s, i, size - i - 2);
    }
    return true;
  }

  bool isPalindrome(string s, int start, int end) {
    if (start >= end)return true;
    for (int i = 0; i <= (end - start) / 2; i++) {
      if (s[start + i] != s[end - i])return false;
    }
    return true;
  }
};