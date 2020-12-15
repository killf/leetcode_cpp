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


class MyHashSet {
private:
  struct Node {
    int key;
    Node *next;
  };

public:
  MyHashSet() {}

  void add(int key) {
    int loc = key % 1000;
    for (auto *p = data[loc]; p; p = p->next)if (p->key == key)return;
    data[loc] = new Node{.key=key, .next=data[loc]};
  }

  void remove(int key) {
    int loc = key % 1000;
    Node *p = data[loc];
    if (!p)return;
    if (p->key == key) {
      data[loc] = p->next;
      delete p;
      return;
    }

    for (; p->next; p = p->next) {
      if (p->next->key == key) {
        auto *q = p->next;
        p->next = q->next;
        delete q;
        return;
      }
    }
  }

  bool contains(int key) {
    int loc = key % 1000;
    for (auto *p = data[loc]; p; p = p->next)if (p->key == key)return true;
    return false;
  }

private:
  Node *data[1000] = {};
};