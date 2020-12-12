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
    int islandPerimeter(vector<vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();

        int n = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0)continue;

                if (r - 1 < 0 || grid[r - 1][c] == 0)n++;
                if (r + 1 > rows - 1 || grid[r + 1][c] == 0)n++;
                if (c - 1 < 0 || grid[r][c - 1] == 0)n++;
                if (c + 1 > cols - 1 || grid[r][c + 1] == 0)n++;
            }
        }
        return n;
    }
};

