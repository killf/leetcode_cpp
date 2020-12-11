#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)return 0;
    if (root->left && !root->left->left && !root->left->right)return root->left->val + sumOfLeftLeaves(root->right);

    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};