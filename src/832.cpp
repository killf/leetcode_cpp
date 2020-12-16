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

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int row = A.size(), col = A[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col / 2; j++)swap(A[i][j], A[i][col - j - 1]);
            for (int j = 0; j < col; j++)A[i][j] = 1 - A[i][j];
        }
        return A;
    }
};

int main() {
    vector<vector<int>> A = {{1, 1, 0, 0},
                             {1, 0, 0, 1},
                             {0, 1, 1, 1},
                             {1, 0, 1, 0}};
    Solution solution;
    solution.flipAndInvertImage(A);
    return 0;
}