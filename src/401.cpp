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
#include <iomanip>

using namespace std;

class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    int d[60];
    for (int i = 0; i < 60; i++)d[i] = ones(i);

    vector<string> result;
    for (int h = 0; h < 12; h++) {
      for (int m = 0; m < 60; m++) {
        if (d[h] + d[m] == num) {
          stringstream ss;
          ss << h << ":" << setw(2) << setfill('0') << m;
          result.push_back(ss.str());
        }
      }
    }
    return result;
  }

  int ones(int n) {
    int r = 0;
    while (n) {
      n = n & (n - 1);
      r++;
    }
    return r;
  }
};