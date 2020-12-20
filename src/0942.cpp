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

using namespace std;

class Solution {
public:
  vector<int> diStringMatch(string S) {
    int a = 0, b = S.length();
    vector<int> result;
    for (auto &s:S) if (s == 'I') result.push_back(a++); else result.push_back(b--);
    result.push_back(a);
    return result;
  }
};