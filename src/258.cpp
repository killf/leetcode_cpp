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
    int addDigits(int num) {
        if (num < 10)return num;

        int sum = 0;
        while (num >= 10) {
            sum += num % 10;
            num = num / 10;
        }
        sum += num;

        return addDigits(sum);
    }
};