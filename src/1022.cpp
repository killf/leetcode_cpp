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

/*树的遍历，关键点在于递归状态、每次递归做的事情、终止条件*/
class Solution {
public:
  int sumRootToLeaf(TreeNode *root) {
    int sum = 0;
    visit(root, 0, sum);
    return sum;
  }

  void visit(TreeNode *root, int n, int &sum) {
    if (!root)return;

    n <<= 1;
    n |= root->val;
    if (!root->left && !root->right) {
      sum += n;
      return;
    }

    if (root->left)visit(root->left, n, sum);
    if (root->right)visit(root->right, n, sum);
  }
};