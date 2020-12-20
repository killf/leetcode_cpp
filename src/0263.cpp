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
    bool isUgly(int num) {
        if (num <= 0)return false;
        if (num == 1)return true;
        if (num % 2 == 0)return isUgly(num / 2);
        if (num % 3 == 0)return isUgly(num / 3);
        if (num % 5 == 0)return isUgly(num / 5);
        return false;
    }
};