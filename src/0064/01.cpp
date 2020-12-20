#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void step(vector<vector<int>> &grid, int r, int c, int n, int &result) {
        n += grid[r][c];
        if (r == grid.size() - 1 && c == grid[0].size() - 1) {
            result = result > 0 ? min(result, n) : n;
            return;
        }

        if (r < grid.size() - 1) step(grid, r + 1, c, n, result);
        if (c < grid[0].size() - 1) step(grid, r, c + 1, n, result);
    }

    int minPathSum(vector<vector<int>> &grid) {
        int result = 0;
        step(grid, 0, 0, 0, result);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };

    cout << solution.minPathSum(grid) << endl;
    return 0;
}