#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

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
  bool isSubtree(TreeNode *s, TreeNode *t) {
    return isSame(s, t) || s && (isSubtree(s->left, t) || isSubtree(s->right, t));
  }

  bool isSame(TreeNode *a, TreeNode *b) {
    return (!a && !b) || a && b && a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
  }
};