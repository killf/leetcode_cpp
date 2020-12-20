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

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    char counter[26] = {};
    for (auto c:A[0]) counter[c - 'a']++;

    for (int i = 1; i < A.size(); i++) {
      char tmp[26] = {};
      for (auto c:A[i])tmp[c - 'a']++;

      for (int j = 0; j < 26; j++)counter[j] = min(counter[j], tmp[j]);
    }

    vector<string> result;
    for (char i = 0; i < 26; i++) {
      for (int j = 0; j < counter[i]; j++) {
        result.emplace_back(1, 'a' + i);
      }
    }

    return result;
  }
};