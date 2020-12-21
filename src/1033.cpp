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

/*贪心*/
class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    if (a > b)swap(a, b);
    if (b > c)swap(b, c);
    if (a > b)swap(a, b);

    int minimum_moves = 0, maximum_moves = 0;
    if (a + 1 < b) {
      minimum_moves++;
      maximum_moves += b - a - 1;
    }
    if (b + 1 < c) {
      minimum_moves++;
      maximum_moves += c - b - 1;
    }
    return {minimum_moves, maximum_moves};
  }
};

int main() {
  Solution solution;
  solution.numMovesStones(4, 3, 2);
  return 0;
}