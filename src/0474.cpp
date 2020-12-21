#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void count(const string &s, int &zeros, int &ones) {
        zeros = ones = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            if (s[i] == '1') ones++;
            else zeros++;
        }
    }

    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> result(m + 1, vector<int>(n + 1));

        int zeros, ones;
        for (const auto &s:strs) {
            counts(s, zeros, ones);
            for (int r = m; r >= zeros; r--) {
                for (int c = n; c >= ones; c--) {
                    result[r][c] = max(1 + result[r - zeros][c - ones], result[r][c]);
                }
            }
        }

        return result[m][n];
    }
};