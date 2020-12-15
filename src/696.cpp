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
  int countBinarySubstrings(string s) {
    char k = s[0];
    int count = 1, last = -1, sum = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == k) count++;
      else {
        if (last > -1) sum += min(last, count);
        last = count;
        count = 1;
        k = s[i];
      }
    }
    if (last > -1) sum += min(last, count);
    return sum;
  }
};

int main() {
  Solution solution;
  solution.countBinarySubstrings("00110");
  return 0;
}