#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int mySqrt(int c) {
    float x = float(c), y;
    do {
      y = x * x - float(c);
      x = x - y / (2 * x);
    } while (y > 0.1);
    return int(x);
  }
};

int main() {
  Solution solution;
  cout << solution.mySqrt(88) << endl;
}