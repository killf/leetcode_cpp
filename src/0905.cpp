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

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &A) {
    int size = A.size(), i = 0, j = size - 1;
    while (i < j) {
      while (i < j && !(A[i] & 1))i++;
      while (i < j && (A[j] & 1))j--;
      if (i >= j)break;

      swap(A[i++], A[j--]);
    }
    return A;
  }
};
