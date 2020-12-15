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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> sum;
    vector<int> count;
    visit(root, sum, count, 1);

    for (int i = 0; i < sum.size(); i++)sum[i] /= count[i];
    return sum;
  }

  void visit(TreeNode *root, vector<double> &sum, vector<int> &count, int depth) {
    if (!root)return;
    if (sum.size() < depth) {
      sum.resize(depth);
      count.resize(depth);
    }

    sum[depth - 1] += root->val;
    count[depth - 1]++;

    visit(root->left, sum, count, depth + 1);
    visit(root->right, sum, count, depth + 1);
  }
};