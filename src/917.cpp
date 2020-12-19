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

using namespace std;

class Solution {
public:
  string reverseOnlyLetters(string S) {
    if (S.size() <= 1)return S;

    int size = S.size(), i = 0, j = size - 1;
    while (i < j) {
      while (i < j && !isalpha(S[i]))i++;
      while (i < j && !isalpha(S[j]))j--;
      if (i >= j)break;

      swap(S[i++], S[j--]);
    }

    return S;
  }
};