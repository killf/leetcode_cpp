struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool visit(TreeNode *a, TreeNode *b) {
    if (!a && !b)return true;
    if (a && !b || !a && b || a->val != b->val)return false;

    return visit(a->left, b->right) && visit(a->right, b->left);
  }

  bool isSymmetric(TreeNode *root) {
    return visit(root, root);
  }
};