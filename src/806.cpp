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
#include <bitset>
#include <set>

using namespace std;

class Solution {
public:
  vector<int> numberOfLines(vector<int> &widths, string s) {
    int row = 1, col = 100;
    for (auto c:s) {
      int len = widths[c - 'a'];
      if (col >= len) col -= len;
      else {
        row++;
        col = 100 - len;
      }
    }
    return {row, 100 - col};
  }
};

int main() {
  vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                        10, 10};
  string s = "bbbcccdddaaa";
  Solution solution;
  solution.numberOfLines(widths, s);
  return 0;
}