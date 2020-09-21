#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int visit(TreeNode *root) {
    if (!root)return 0;

    int left = visit(root->left);
    int right = visit(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)return -1;
    return max(left, right) + 1;
  }

  bool isBalanced(TreeNode *root) {
    return visit(root) != -1;
  }
};