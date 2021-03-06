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

/*先进后出->括号匹配问题->栈*/
class Solution {
public:
  string removeDuplicates(string S) {
    string r;
    for (auto c:S) {
      if (r.back() == c) r.pop_back(); else r.push_back(c);
    }
    return r;
  }
};