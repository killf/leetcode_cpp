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
  int getMinimumDifference(TreeNode *root) {
    int result = -1, last;
    visit(root, last, result);
    return result;
  }

  void visit(TreeNode *root, int &last, int &result) {
    if (!root)return;
    visit(root->left, last, result);

    if (result == -1) result = 0;
    else if (result == 0) result = root->val - last;
    else result = min(result, root->val - last);
    last = root->val;

    visit(root->right, last, result);
  }
};

