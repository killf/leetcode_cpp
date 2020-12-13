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
    string licenseKeyFormatting(string S, int K) {
        stringstream ss;
        int k = K;
        for (int i = S.size() - 1; i >= 0; i--) {
            char c = S[i];
            if (c == '-')continue;

        }
    }
};