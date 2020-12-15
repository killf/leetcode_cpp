#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>
#include <stack>

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
  int findSecondMinimumValue(TreeNode *root) {
    if (!root)return -1;

    stack<TreeNode *> stack;
    stack.push(root);

    int result = -1, first = root->val;
    while (!stack.empty()) {
      auto node = stack.top();
      stack.pop();
      if (!node->left && !node->right)continue;

      if (node->left->val == first)stack.push(node->left);
      else if (result == -1)result = node->left->val;
      else result = min(result, node->left->val);

      if (node->right->val == first)stack.push(node->right);
      else if (result == -1)result = node->right->val;
      else result = min(result, node->right->val);
    }
    return result;
  }
};