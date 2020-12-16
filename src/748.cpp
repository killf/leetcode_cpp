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

using namespace std;


inline int get_loc(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A';
  if (c >= 'a' && c <= 'z') return c - 'a';
  return -1;
}

inline void distance(const int flags[26], string &s, int &min_len, string &result) {
  int loc, d = 0, counter[26];
  for (int i = 0; i < 26; i++)counter[i] = flags[i];

  for (auto c:s) {
    if ((loc = get_loc(c)) < 0)continue;
    if (--counter[loc] < 0)d++;
  }

  for (int i = 0; i < 26; i++) {
    if (flags[i] > 0 && counter[i] > 0)return;
  }

  if (result.empty() || d < min_len) {
    result = s;
    min_len = d;
  }
}

class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    int counter[26] = {}, loc, min_len;
    for (auto c:licensePlate)if ((loc = get_loc(c)) >= 0)counter[loc]++;

    string result;
    for (auto &w:words) distance(counter, w, min_len, result);
    return result;
  }
};

int main() {
  string licensePlate = "s";
  vector<string> words = {"looks", "pest", "stew", "show"};

  Solution solution;
  solution.shortestCompletingWord(licensePlate, words);
  return 0;
}