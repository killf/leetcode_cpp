#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;


// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};


class Solution {
public:
  int maxDepth(Node *root) {
    if (!root)return 0;

    int depth = 0;
    for (auto node:root->children) {
      depth = max(depth, maxDepth(node));
    }

    return depth + 1;
  }
};