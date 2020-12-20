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

using namespace std;

class Solution {
public:
  int getSum(unsigned int a, unsigned b) {
    while (b) {
      auto c = a^b;
      b = (a & b) << 1;
      a = c;
    }
    return a;
  }
};

int main() {
  Solution solution;
  auto v = solution.getSum(-1, 1);
  return v;
}