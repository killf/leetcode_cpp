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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {
    vector<TreeNode *> nodes;
    visit(root, nodes);

    for (int i = 0; i < nodes.size(); i++) {
      nodes[i]->right = i >= nodes.size() - 1 ? nullptr : nodes[i + 1];
      nodes[i]->left = nullptr;
    }

    return nodes[0];
  }

  void visit(TreeNode *node, vector<TreeNode *> &nodes) {
    if (!node)return;

    visit(node->left, nodes);
    nodes.push_back(node);
    visit(node->right, nodes);
  }
};
