#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    int m[128] = {0};
    for (auto c:s)m[c]++;

    bool has_odd = false;
    int sum = 0;
    for (int i = 0; i < 128; i++) {
      if (m[i] % 2) {
        has_odd = true;
        sum += m[i] - 1;
      } else sum += m[i];
    }

    return has_odd ? sum + 1 : sum;
  }
};