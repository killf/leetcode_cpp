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

  TreeNode *visit(TreeNode *root, vector<int> &nums, int left, int right) {
    int i = (left + right) / 2;
    auto node = new TreeNode(nums[i]);

  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return visit(nullptr, nums, 0, nums.size() - 1);
  }
};