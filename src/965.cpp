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
#include <set>
#include <list>
#include <cstring>
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
  bool isUnivalTree(TreeNode *root) {
    if (!root)return true;
    return visit(root, root->val);
  }

  bool visit(TreeNode *root, int value) {
    if (!root)return true;

    if (root->val != value)return false;
    return visit(root->left, value) && visit(root->right, value);
  }
};