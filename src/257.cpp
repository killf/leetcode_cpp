#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
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
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root)return {};
        if (!root->left && !root->right)return {to_string(root->val)};

        auto left = binaryTreePaths(root->left);
        auto right = binaryTreePaths(root->right);

        vector<string> paths;
        for (const auto &iter:left) paths.push_back(to_string(root->val) + "->" + iter);
        for (const auto &iter:right) paths.push_back(to_string(root->val) + "->" + iter);
        return paths;
    }
};