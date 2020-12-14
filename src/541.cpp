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
  string reverseStr(string s, int k) {
    int i = 0, step = 2 * k, end = s.size() - 1;
    for (; i + step < end; i += step)reverse(s, i, k);

    if (end - i + 1 <= k) reverse(s, i, end - i + 1); else reverse(s, i, k);
    return s;
  }

  void reverse(string &s, int i, int k) {
    if (k <= 0 || i + k > s.size())return;

    for (int j = 0; j < k / 2; j++) {
      swap(s[i + j], s[i + k - j - 1]);
    }
  }
};