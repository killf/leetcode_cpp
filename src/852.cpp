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
    int peakIndexInMountainArray(vector<int> &arr) {
        for (int i = 1; i < arr.size() - 1; i++)if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])return i;
        return -1;
    }
};