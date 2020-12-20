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
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() < 2 || B.size() < 2)return false;

        vector<int> indices;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                indices.push_back(i);
                if (indices.size() > 2)return false;
            }
        }

        if (indices.size() == 1)return false;
        else if (indices.size() == 2)return A[indices[0]] == B[indices[1]] && A[indices[1]] == B[indices[0]];

        int counter[26] = {};
        for (auto c:A) if (++counter[c - 'a'] >= 2)return true;
        return false;
    }
};