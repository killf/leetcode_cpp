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
  int findLUSlength(string a, string b) {
    if (a.size() != b.size())return max(a.size(), b.size());
    if (a == b)return -1; else return a.size();
  }
};