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
#include <bitset>

using namespace std;

class Solution {
public:
  bool rotateString(string A, string B) {
    if (A.size() != B.size())return false;
    if(A.empty())return true;

    for (int i = 0; i < A.size(); i++) {
      char c = A[0];
      A.erase(0, 1);
      A += c;

      if(A==B)return true;
    }

    return false;
  }
};