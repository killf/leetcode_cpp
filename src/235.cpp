#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)return root;

    TreeNode *node;
    if (root->left && (node = lowestCommonAncestor(root->left, p, q)))return node;
    if (root->right && (node = lowestCommonAncestor(root->right, p, q)))return node;
  }

  TreeNode *find(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return root;
    if (root == p || root == q)return root;

    TreeNode *node;
    if (root->left && (node = find(root->left, p, q)))return node;
    if (root->right && (node = find(root->right, p, q)))return node;
    return nullptr;
  }
};