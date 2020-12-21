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
#include <bitset>

using namespace std;


/*排序问题：自定义排序*/
class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    int order[1001] = {};
    for (int i = 0; i < arr2.size(); i++)order[arr2[i]] = i + 1;

    stable_sort(arr1.begin(), arr1.end(), [&order](int a, int b) {
      int ai = order[a], bi = order[b];
      if (ai > 0 && bi > 0)return ai < bi;
      if (ai > 0 && bi == 0)return true;
      if (ai == 0 && bi > 0)return false;
      return a < b;
    });

    return arr1;
  }
};

int main() {
  vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19},
    arr2 = {2, 1, 4, 3, 9, 6};

  Solution solution;
  solution.relativeSortArray(arr1, arr2);
  return 0;
}