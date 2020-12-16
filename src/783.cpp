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
#include <queue>
#include <bitset>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    TreeNode *last = nullptr;
    int result = INT32_MAX;
    visit(root, last, result);
    return result;
  }

  void visit(TreeNode *root, TreeNode *&last, int &result) {
    if (!root)return;

    visit(root->left, last, result);

    if (last) {
      int val = root->val - last->val;
      if (val < result)result = val;
    }
    last = root;

    visit(root->right, last, result);
  }
};