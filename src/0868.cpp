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
    int binaryGap(int n) {
        int last = -1, pos = 1, d = 0;
        while (pos < 32) {
            if (n & 1) {
                if (last != -1)d = max(d, pos - last);
                last = pos;
            }
            n >>= 1;
            pos++;
        }
        return d;
    }
};