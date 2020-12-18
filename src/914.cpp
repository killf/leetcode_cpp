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
      if(p->value==value){
        p->count++;
        return;
      }

    }

  }

private:
  hash<int> hash;
  Node *data[1024] = {};
};


class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {

  }
};