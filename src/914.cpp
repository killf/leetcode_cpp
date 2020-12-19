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

inline int common_divisor(int a, int b) {
  if (a < b)swap(a, b);

  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }

  return a;
}

class HashSet {
private:
  struct Node {
    int value;
    int count;
    Node *next;
  };

public:
  void insert(int value) {
    auto loc = hash(value) % 1024;

    for (auto *p = data[loc]; p; p = p->next) {
      if (p->value == value) {
        p->count++;
        return;
      }
    }

    data[loc] = new Node{value, 1, data[loc]};
  }

  vector<int> counts() {
    vector<int> counts;

    for (int i = 0; i < 1024; i++) {
      for (auto *p = data[i]; p; p = p->next) {
        counts.push_back(p->count);
      }
    }

    return counts;
  }


private:
  hash<int> hash;
  Node *data[1024] = {};
};


class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    HashSet hashSet;
    for (auto d:deck)hashSet.insert(d);

    auto counts = hashSet.counts();
    int result = counts[0];

    for (int i = 1; i < counts.size(); i++) {
      result = common_divisor(result, counts[i]);
    }

    return result > 1;
  }
};
