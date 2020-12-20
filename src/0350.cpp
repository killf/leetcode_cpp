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

template<typename T, int S = 1024>
class HashSet {
private:
  struct Node {
    T val;
    Node *next;
  };

public:
  HashSet() : data(S) {}

  void insert(const T &value) {
    int m = hash(value) % S;
    auto *node = new Node{.val = value, .next = data[m]};
    data[m] = node;
  }

  bool remove(const T &value) {
    int m = hash(value) % S;
    for (Node *p = data[m], *q = nullptr; p; q = p, p = p->next) {
      if (p->val == value) {
        if (q) q->next = p->next;
        else data[m] = p->next;
        return (delete p, true);
      }
    }
    return false;
  }

private:
  vector<Node *> data;
  hash<T> hash;
};

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty() || nums2.empty())return {};
    if (nums1.size() > nums2.size())swap(nums1, nums2);

    HashSet<int> hashSet;
    for (auto n: nums1) hashSet.insert(n);

    vector<int> result;
    for (auto n : nums2) {
      if (hashSet.remove(n))result.push_back(n);
    }
    return result;
  }
};

