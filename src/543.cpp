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

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root)return 0;
    return get<0>(visit(root)) - 1;
  }

  tuple<int, int> visit(TreeNode *root) {
    if (!root)return {0, 0};

    auto[left, left_path] = visit(root->left);
    auto[right, right_path] = visit(root->right);

    auto cur = left_path + right_path + 1;
    cur = max(cur, max(left, right));

    int cur_path = max(left_path, right_path) + 1;
    return {cur, cur_path};
  }
};