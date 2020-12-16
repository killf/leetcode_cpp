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
#include <bitset>
#include <set>

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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1, leaf2;
        visit(root1, leaf1);
        visit(root2, leaf2);

        if (leaf1.size() != leaf2.size())return false;
        for (int i = 0; i < leaf1.size(); i++)if (leaf1[i] != leaf2[i])return false;
        return true;
    }

    inline void visit(TreeNode *root, vector<int> &leaf) {
        if (!root)return;

        visit(root->left, leaf);
        visit(root->right, leaf);

        if (!root->left && !root->right)leaf.push_back(root->val);
    }
};