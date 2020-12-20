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
  string toLowerCase(string str) {
    for (auto &c:str) {
      if (c >= 'A' && c <= 'Z')c -= 'A' - 'a';
    }
    return str;
  }
};