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
  int minDepth(TreeNode *root) {
    if (!root)return 0;

    int n = 1;
    vector<TreeNode *> next = {root}, next_pre;
    while (!next.empty()) {
      for (const auto &iter:next) {
        if (iter->left) next_pre.push_back(iter->left);
        if (iter->right) next_pre.push_back(iter->right);
        if (!iter->left && !iter->right) return n;
      }
      swap(next_pre, next);
      next_pre.clear();
      n++;
    }
    return n;
  }
};