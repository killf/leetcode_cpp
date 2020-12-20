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
  int visit(TreeNode *n, int c) {
    if (!n)return 0;
    return max(visit(n->left, c + 1), visit(n->right, c + 1)) + 1;
  }

  int maxDepth(TreeNode *root) {
    return visit(root, 0);
  }
};