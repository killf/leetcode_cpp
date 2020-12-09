#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  int calc(int n) {
    int sum = 0;
    while (n >= 10) {
      int v = n % 10;
      sum += v * v;
      n = n / 10;
    }
    sum += n * n;
    return sum;
  }

  bool isHappy(int n) {
    if (n == 1)return true;




  }
};

int main() {
  Solution solution;
  printf("%d\n", solution.calc(9999));

  map<int, int> m;
  for (int i = 2; i <= 243; i++) {
    m[i] = solution.calc(i);
  }

  return 0;
}
