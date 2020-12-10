#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)return true;
        return !canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3);
    }
};