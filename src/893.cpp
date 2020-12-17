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

inline void counter_count(char *counter, string &s) {
  for (int i = 0; i < s.size(); i++) {
    counter[s[i] - 'a' + 26 * (i % 2)]++;
  }
}

inline bool counter_compare(char *counter1, char *counter2) {
  int *p1 = (int *) counter1, *p2 = (int *) counter2;
  for (int i = 0; i < 13; i++)if (*p1++ != *p2++)return false;
  return true;
}

inline void counter_reset(char *counter) {
  auto *p = (int *) counter;
  for (int i = 0; i < 13; i++)*p++ = 0;
}

class HashSet {
private:
  struct Node {
    char data[52];
    Node *next;
  };

public:
  void insert(string &s) {
    Node *node = new Node{};
    counter_reset(node->data);
    counter_count(node->data, s);

    auto loc = hash(node->data) % 1024;
    for (auto *p = data[loc]; p; p = p->next) {
      if (counter_compare(node->data, p->data))return;
    }

    node->next = data[loc];
    data[loc] = node;
    size++;
  }

  size_t hash(const char *counter) {
    size_t loc = 0;
    for (int i = 0; i < 52; i++) {
      loc += counter[i] * (i + 1);
    }
    return loc;
  }

  int size = 0;

private:
  Node *data[1024] = {};
};


class Solution {
public:
  int numSpecialEquivGroups(vector<string> &A) {
    HashSet set;
    for (auto &s:A)set.insert(s);
    return set.size;
  }
};

