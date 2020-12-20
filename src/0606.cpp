#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  string tree2str(TreeNode *t) {
    if (!t) return "";

    string left = tree2str(t->left);
    string right = tree2str(t->right);

    string s = to_string(t->val);

    if (t->left && t->right) s += "(" + left + ")(" + right + ")";
    else if (t->left && !t->right) s += "(" + left + ")";
    else if (!t->left && t->right) s += "()(" + right + ")";
    return s;
  }
};