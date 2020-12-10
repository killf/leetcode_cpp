#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)return root;

    auto *left = root->left, *right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
  }
};
