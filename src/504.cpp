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
  string convertToBase7(int num) {
    if (num == 0)return "0";

    stringstream ss;
    bool is_neg = num < 0;
    if (is_neg)num = -num;

    while (num > 0) {
      ss << num % 7;
      num /= 7;
    }
    if (is_neg)ss << "-";

    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() {
  Solution solution;
  solution.convertToBase7(0);

  return 0;
}