#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();

        for (int r = 1; r < row; r++) grid[r][0] += grid[r - 1][0];
        for (int c = 1; c < col; c++) grid[0][c] += grid[0][c - 1];

        for (int r = 1; r < row; r++) {
            for (int c = 1; c < col; c++) {
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
            }
        }

        return grid[row - 1][col - 1];
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