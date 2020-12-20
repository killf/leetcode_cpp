#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class HashSet {
public:
  void insert(char c, int index) {
    data[c - 'a'].push_back(index);
  }

  void build_index(int size) {
    for (int i = 0; i < 26; i++) {
      if (data[i].empty())continue;

      vector<int> v = data[i];
      data[i].clear();

      for (int t = 0; t <= v[0]; t++) data[i].push_back(v[0]);
      for (int j = 0; j < v.size() - 1; j++) {
        for (int t = v[j]; t < v[j + 1]; t++) data[i].push_back(v[j + 1]);
      }
      for (int t = v[v.size() - 1]; t < size; t++) data[i].push_back(-1);
    }
  }

  int find(char c, int last_index) {
    auto &v = data[c - 'a'];
    if (v.empty())return -1;
    return v[last_index];
  }

private:
  vector<int> data[26];
};

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.empty())return true;
    if (t.empty())return false;

    HashSet hashSet;
    for (int i = 0; i < t.size(); i++)hashSet.insert(t[i], i);
    hashSet.build_index(t.size());

    int index = 0;
    for (auto c:s) {
      if ((index = hashSet.find(c, index)) == -1)return false;
      index++;
    }

    return true;
  }
};

int main() {
  Solution solution;
  auto v = solution.isSubsequence("aaaaaa", "bbaaaa");
  return 0;
}