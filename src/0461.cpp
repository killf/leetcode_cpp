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
    int hammingDistance(int x, int y) {
        int c = x ^y;

        int num = 0;
        while (c) {
            num++;
            c = c & (c - 1);
        }
        return num;
    }
};

int main() {
    Solution solution;
    solution.hammingDistance(3, 1);
    return 0;
}