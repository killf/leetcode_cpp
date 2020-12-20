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

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)return root;

        vector<TreeNode *> p1, p2;
        if (!find(root, p, p1))return nullptr;
        if (!find(root, q, p2))return nullptr;

        size_t size = min(p1.size(), p2.size());
        for (size_t i = 0; i < size; i++) {
            if (p1[i] != p2[i]) {
                if (i == 0)return nullptr;
                else return p1[i - 1];
            }
        }

        return p1[size - 1];
    }

    bool find(TreeNode *root, TreeNode *p, vector<TreeNode *> &path) {
        if (!root)return false;

        path.push_back(root);
        if (root == p) return true;

        if (find(root->left, p, path)) return true;
        if (find(root->right, p, path)) return true;

        path.pop_back();
        return false;
    }
};