#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int index1 = 0, index2 = numbers.size() - 1, sum = numbers[index1] + numbers[index2];

    while (index1 < index2) {
      if (sum > target)sum = numbers[index1] + numbers[--index2];
      else if (sum < target) sum = numbers[++index1] + numbers[index2];
      else if (sum == target)return {index1 + 1, index2 + 1};
    }

    return {};
  }
};