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

class HashSet {
private:
  struct Node {
    int val;
    Node *next;
  };

public:
  void insert(int val) {
    size_t loc = hash(val) % 1024;
    data[loc] = new Node{val, data[loc]};
  }

  bool contain(int val) {
    size_t loc = hash(val) % 1024;
    for (Node *p = data[loc]; p; p = p->next) {
      if (p->val == val)return true;
    }
    return false;
  }

private:
  hash<int> hash;
  Node *data[1024] = {};
};

class Solution {
public:
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    int sum = 0;
    for (auto n:A)sum += n;
    for (auto n:B)sum -= n;
    sum /= 2;

    HashSet set;
    for (auto n:A)set.insert(n);

    for (auto b:B)if (set.contain(sum + b))return {sum + b, b};
    return {};
  }
};