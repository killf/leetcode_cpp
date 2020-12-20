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
  TreeNode *visit(vector<int> &nums, int left, int right) {
    if (left > right)return nullptr;
    int i = (left + right) / 2;
    auto node = new TreeNode(nums[i]);
    node->left = visit(nums, left, i - 1);
    node->right = visit(nums, i + 1, right);
    return node;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return visit(nums, 0, nums.size() - 1);
  }
};