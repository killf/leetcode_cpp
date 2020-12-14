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
  vector<int> preorder(Node *root) {
    vector<int> result;
    visit(root, result);
    return result;
  }

  void visit(Node *root, vector<int> &result) {
    if (!root)return;

    result.push_back(root->val);
    for (const auto &node:root->children)visit(node, result);
  }
};