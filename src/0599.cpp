#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
class HashMap {
private:
  struct Node {
    Node *next;
    T1 key;
    T2 value;
  };

public:
  T2 &operator[](const T1 &key) {
    int m = hash(key) % 1024;
    for (auto p = data[m]; p; p = p->next) {
      if (p->key == key)return p->value;
    }
    data[m] = new Node{.next=data[m], .key=key};
    return data[m]->value;
  }

  bool contain(const T1 &key) {
    int m = hash(key) % 1024;
    for (auto p = data[m]; p; p = p->next) {
      if (p->key == key)return true;
    }
    return false;
  }

private:
  hash<T1> hash;
  Node *data[1024] = {nullptr};
};

class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    if (list1.size() < list2.size())swap(list1, list2);

    HashMap<string, int> map;
    for (int i = 0; i < list1.size(); i++)map[list1[i]] = i;

    vector<string> result;
    int sum;
    for (int i = 0; i < list2.size(); i++) {
      string &s = list2[i];
      if (!map.contain(s))continue;

      if (result.empty()) {
        sum = i + map[s];
        result.push_back(s);
      } else {
        int t = i + map[s];
        if (t == sum) {
          result.push_back(s);
        } else if (t < sum) {
          result.clear();
          result.push_back(s);
          sum = t;
        }
      }
    }

    return result;
  }
};

int main() {
  string s1 = "123";
  string s2 = "123";
  auto b = s1 == s2;

  return 0;
}