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

class BitSet {
public:
  explicit BitSet(size_t max_size) : max_size(max_size) {
    data = new char[max_size / 8 + 1]{};
  }

  void set(size_t pos) {
    auto[a, b]=div(pos, 8);
    data[a] |= 1 << b;
  }

  bool get(size_t pos) {
    auto[a, b]=div(pos, 8);
    return data[a] & (1 << b);
  }

private:
  char *data;
  size_t max_size;
};

inline void counter_count(char *counter, string &s) {
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (i & 1) counter[c + 26]++;
    else counter[c]++;
  }
}

inline bool counter_compare(char *counter, string &s) {
  char data[52];

  int *p1 = (int *) data, *p2 = (int *) counter;
  for (int i = 0; i < 13; i++)*p1++ = *p2++;

  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    char v;
    if (i & 1) v = --data[c + 26];
    else v = --data[c];
    if (v < 0)return false;
  }

  return true;
}

inline void counter_reset(char *counter) {
  auto *p = (int *) counter;
  for (int i = 0; i < 13; i++)*p++ = 0;
}


class Solution {
public:
  int numSpecialEquivGroups(vector<string> &A) {
    BitSet flags(A.size());

    int result = 0;
    char counter[52] = {};
    for (int i = 0; i < A.size(); i++) {
      if (flags.get(i))continue;

      counter_reset(counter);
      counter_count(counter, A[i]);
      flags.set(i);
      result++;

      for (int j = i + 1; j < A.size(); j++) {
        if (counter_compare(counter, A[j])) {
          flags.set(j);
          continue;
        }
      }
    }

    return result;
  }
};

int main() {
  cout << true << false;

  return 0;
}