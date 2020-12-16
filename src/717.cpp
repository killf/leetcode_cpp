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
  bool isOneBitCharacter(vector<int> &bits) {
    int i = 0, size = bits.size();
    while (i < size - 1) {
      if (bits[i] == 1)i += 2;
      else i++;
    }

    return i == size - 1;
  }
};