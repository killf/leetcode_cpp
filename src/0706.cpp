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


class MyHashMap {
private:
  struct Node {
    int key;
    int value;
    Node *next;
  };
public:
  MyHashMap() {}

  void put(int key, int value) {
    int loc = key % 1000;
    for (auto *p = data[loc]; p; p = p->next)
      if (p->key == key) {
        p->value = value;
        return;
      }
    data[loc] = new Node{.key=key, .value=value, .next=data[loc]};
  }

  int get(int key) {
    int loc = key % 1000;
    for (auto *p = data[loc]; p; p = p->next)if (p->key == key)return p->value;
    return -1;
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

private:
  Node *data[1000] = {};
};
