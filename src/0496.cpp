#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty())return {};
    if (nums2.size() == 1)return {-1};

    map<int, int> map;
    for (int i = 0; i < nums2.size(); i++)map[nums2[i]] = i;

    vector<int> result;
    for (auto n:nums1) {
      bool found = false;
      for (int i = map[n] + 1; i < nums2.size(); i++) {
        if (nums2[i] > n) {
          found = true;
          result.push_back(nums2[i]);
          break;
        }
      }
      if (!found)result.push_back(-1);
    }

    return result;
  }
};