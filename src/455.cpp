#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (g.empty() || s.empty())return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int num = 0, j = g.size() - 1;
        for (int i = s.size() - 1; i >= 0 && j >= 0;) {
            if (s[i] >= g[j]) {
                num++;
                i--;
            }
            j--;
        }

        return num;
    }
};

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    Solution solution;
    auto ret = solution.findContentChildren(g, s);

    return 0;
}
