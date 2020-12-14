#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    vector<int> result;
    int count = 0, max_count = 0, base;
    visit(root, count, max_count, base, result);
    return result;
  }

  void visit(TreeNode *root, int &count, int &max_count, int &base, vector<int> &result) {
    if (!root)return;
    visit(root->left, count, max_count, base, result);

    if (result.empty())base = root->val;
    if (root->val == base) count++;
    else {
      count = 1;
      base = root->val;
    }

    if (count == max_count)result.push_back(base);
    else if (count > max_count) {
      result.clear();
      result.push_back(base);
      max_count = count;
    }

    visit(root->right, count, max_count, base, result);
  }
};