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

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty() || nums2.empty())return {};

//    __gnu_cxx::hash_set<int> set1, set2;
    set<int> set1, set2;
    for (auto n:nums1)set1.insert(n);
    for (auto n:nums2)set2.insert(n);

    vector<int> result;
    for (auto n:set1) {
      if (set2.find(n) != set2.end()) {
        result.push_back(n);
      }
    }

    return result;
  }
};

