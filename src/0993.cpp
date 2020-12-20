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

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isCousins(TreeNode *root, int x, int y) {
    TreeNode *p1, *p2;
    int d1 = 0, d2 = 0;
    if (visit(root, x, nullptr, 0, p1, d1) && visit(root, y, nullptr, 0, p2, d2))return d1 == d2 && p1 != p2;
    return false;
  }

  bool visit(TreeNode *root, int x, TreeNode *last, int depth, TreeNode *&parent, int &path) {
    if (!root)return false;
    if (root->val == x) {
      parent = last;
      path = depth;
      return true;
    }
    return visit(root->left, x, root, depth + 1, parent, path) ||
           visit(root->right, x, root, depth + 1, parent, path);
  }
};