#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>

#include "bitset"

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
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root || root->val < low || root->val > high)return nullptr;

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
  }
};