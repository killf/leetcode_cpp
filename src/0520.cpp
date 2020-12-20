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
  bool detectCapitalUse(string word) {
    int num = 0;
    for (auto c:word)if (isupper(c))num++;
    return num == word.size() || isupper(word[0]) && num == 1 || num == 0;
  }
};