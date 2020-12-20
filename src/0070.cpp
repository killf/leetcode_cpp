#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    // f(n) = f(n-1) + f(n-2)
    if (n == 1)return 1;
    if (n == 2)return 2;

    int a = 1, b = 2, c;
    for (int i = 2; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};

int main() {
  Solution solution;
  cout << solution.climbStairs(44) << endl;
}