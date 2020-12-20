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

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &A, int K) {
    vector<int> result;

    int size = A.size(), i = 0, c = 0;
    while (K > 0 && i < size) {
      int a = A[size - i - 1];
      int b = K % 10;
      int sum = a + b + c;
      result.push_back(sum % 10);

      c = sum / 10;
      K = K / 10;
      i++;
    }

    if (K > 0) {
      K += c;
      while (K > 0) {
        result.push_back(K % 10);
        K = K / 10;
      }
    } else {
      while (i < size) {
        int a = A[size - i - 1];
        int sum = a + c;
        result.push_back(sum % 10);
        c = sum / 10;
        i++;
      }
      if (c > 0)result.push_back(c);
    }

    reverse(result.begin(), result.end());
    return result;
  }
};