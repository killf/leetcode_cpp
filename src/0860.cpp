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
    bool lemonadeChange(vector<int> &bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        for (auto b:bills) {
            switch (b) {
                case 5:
                    c5++;
                    break;
                case 10:
                    c10++;
                    c5--;
                    if (c5 < 0)return false;
                    break;
                case 20:
                    c20++;
                    if (c10 > 0 && c5 > 0) {
                        c10--;
                        c5--;
                    } else if (c5 > 3) c5 -= 3;
                    else return false;
                    break;
            }
        }
        return true;
    }
};