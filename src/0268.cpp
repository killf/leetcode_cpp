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
    int missingNumber(vector<int> &nums) {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += i - nums[i];
        }
        return sum + nums.size();
    }
};