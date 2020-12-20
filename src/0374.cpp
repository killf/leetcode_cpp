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

int guess(int num) {
  int pick = 1702766719;
  if (pick < num)return -1;
  if (pick > num)return 1;
  return 0;
}

class Solution {
public:
  int guessNumber(int n) {
    long a = 1, b = n;
    while (a < b) {
      long c = (a + b) / 2;
      int p = guess((int) c);
      if (p == 0)return c;
      else if (p == -1) {
        if (a + 1 == c)return a;
        b = c;
      } else {
        if (c + 1 == b)return b;
        a = c;
      }
    }
    return a;
  }
};

int main() {
  Solution solution;
  auto v = solution.guessNumber(2126753390);
  return 0;
}