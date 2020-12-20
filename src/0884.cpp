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
#include <set>

using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string A, string B) {
    map<string, int> counterA, counterB;
    int start = 0, end = -1;
    while ((end = A.find(' ', start)) >= 0) {
      if (end > start)counterA[A.substr(start, end - start)]++;
      start = end + 1;
    }
    if (start < A.size())counterA[A.substr(start)]++;

    start = 0, end = -1;
    while ((end = B.find(' ', start)) >= 0) {
      if (end > start)counterB[B.substr(start, end - start)]++;
      start = end + 1;
    }
    if (start < B.size())counterB[B.substr(start)]++;

    vector<string> result;
    for (auto &[k, v]:counterA) {
      if (v != 1)continue;
      if (counterB[k] == 0)result.push_back(k);
    }
    for (auto &[k, v]:counterB) {
      if (v != 1)continue;
      if (counterA[k] == 0)result.push_back(k);
    }

    return result;
  }
};