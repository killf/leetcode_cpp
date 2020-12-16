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

using namespace std;


class Solution {
private:
  struct Node {
    char val;
    Node *left;   // 左孩子
    Node *right;  // 右兄弟
  };

public:
  string longestWord(vector<string> &words) {
    sort(words.begin(), words.end());

    string max_str;
    int max_count = 0;
    for (auto w:words) {
      if (insert(w)) {
        if (w.size() > max_count) {
          max_count = w.size();
          max_str = w;
        } else if (w.size() == max_count) {
          if (w < max_str)max_str = w;
        }
      }
    }

    return max_str;
  }

private:
  bool insert(string &w) {
    Node *p = root;
    for (int i = 0; i < w.size() - 1; i++) {
      char c = w[i];
      p = p->left;
      while (p) {
        if (p->val == c)break;
        p = p->right;
      }
      if (!p)return false;
    }

    char c = w[w.size() - 1];
    if (!p->left)p->left = new Node{c, nullptr, nullptr};
    else {
      for (p = p->left; p; p = p->right) {
        if (p->val == c)return true;
        if (!p->right)break;
      }
      p->right = new Node{c, nullptr, nullptr};
    }
    return true;
  }

private:
  Node *root = new Node{0, nullptr, nullptr};
};

int main() {
  vector<string> words = {"w","wo","wor","worl", "world"};

  Solution solution;
  solution.longestWord(words);

  return 0;
}