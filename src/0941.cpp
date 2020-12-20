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
#include <set>
#include <list>
#include <cstring>

using namespace std;

class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    int size = arr.size();
    if (size < 3 || arr[0] >= arr[1] || arr[size - 2] <= arr[size - 1])return false;

    int i = 1;
    while (i < size - 1) {
      if (arr[i] >= arr[i + 1])break;
      i++;
    }
    if (i >= size)return false;

    while (i < size - 1) {
      if (arr[i] <= arr[i + 1])break;
      i++;
    }
    return i >= size - 1;
  }
};

int main() {
  vector<int> arr = {0, 3, 2, 1};

  Solution solution;
  solution.validMountainArray(arr);
  return 0;
}