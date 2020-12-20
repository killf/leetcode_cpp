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

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root || root->val == val)return root;
    if (val < root->val)return searchBST(root->left, val);
    else return searchBST(root->right, val);
  }
};