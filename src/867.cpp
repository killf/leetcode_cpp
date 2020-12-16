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
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int row = A.size(), col = A[0].size();

        vector<vector<int>> B(col);
        for (int i = 0; i < col; i++)B[i].resize(row);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};