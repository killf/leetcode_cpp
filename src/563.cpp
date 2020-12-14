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
  int findTilt(TreeNode *root) {
    return get<0>(visit(root));
  }

  tuple<int, int> visit(TreeNode *root) {
    if (!root)return {0, 0};

    auto[left, leftSum] = visit(root->left);
    auto[right, rightSum]= visit(root->right);

    int current = abs(leftSum - rightSum);
    return {left + right + current, leftSum + rightSum + root->val};
  }
};