#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> flags(n, true);
    flags[0] = false;
    flags[1] = false;

    int num = 0;
    for (int i = 2; i < n; i++) {
      if (flags[i]) {
        num++;
        for (int j = i * i; j < n; j += i)flags[j] = false;
      }
    }
    return num;
  }
};
