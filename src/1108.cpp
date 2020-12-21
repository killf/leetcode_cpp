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
#include <set>
#include <list>
#include <cstring>
#include <bitset>

using namespace std;


/*字符串替换*/
class Solution {
public:
  string defangIPaddr(string address) {
    string s;
    for (auto c :address) {
      if (c == '.')s += "[.]"; else s += c;
    }
    return s;
  }
};