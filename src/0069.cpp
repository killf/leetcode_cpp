#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int mySqrt(int c) {
    if (c == 0)return 0;

    double x = double(c), y;
    do {
      y = x * x - double(c);
      x = x - y / (2 * x);
    } while (y > 0.1);
    return int(x);
  }
};

int main() {
  Solution solution;
  cout << solution.mySqrt(2147395599) << endl;
}