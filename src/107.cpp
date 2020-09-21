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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (!root)return result;

    vector<TreeNode *> next = {root}, next_pre;
    while (!next.empty()) {
      result.emplace_back();
      auto &back = result.back();
      for (const auto &iter:next) {
        back.emplace_back(iter->val);
        if (iter->left) next_pre.emplace_back(iter->left);
        if (iter->right) next_pre.emplace_back(iter->right);
      }
      swap(next_pre, next);
      next_pre.clear();
    }

    return vector<vector<int>>(result.rbegin(), result.rend());
  }
};