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


/*线性扫描问题*/
class Solution {
public:
  void duplicateZeros(vector<int> &arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
      if (arr[i] == 0) {
        for (int j = size - 2; j >= i; j--) arr[j + 1] = arr[j];
        i++;
      }
    }
  }
};