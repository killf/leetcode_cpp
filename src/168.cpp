#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string s;
    if (n > 26)s += convertToTitle((n - 1) / 26);
    s += 'A' + (n - 1) % 26;
    return s;
  }
};