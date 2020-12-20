#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root)return false;
    if (!root->left && !root->right && root->val == sum) return true;
    return root->left && hasPathSum(root->left, sum - root->val) ||
           root->right && hasPathSum(root->right, sum - root->val);
  }
};