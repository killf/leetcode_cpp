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

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))return true;
        if (!isBadVersion(n))return false;

        long i = 1, j = n;
        while (i < j) {
            int t = (i + j) / 2;
            if (t == i)return j;
            if (isBadVersion(t)) {
                if (i + 1 == t)return t;
                j = t;
            } else {
                if (t + 1 == j)return j;
                i = t;
            }
        }

        return false;
    }
};