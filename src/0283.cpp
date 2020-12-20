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
    void moveZeroes(vector<int> &nums) {
        int zeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)zeroes++;
            else swap(nums[i], nums[i - zeroes]);
        }
    }
};