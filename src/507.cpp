#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num == 1)return false;

    int sum = 1, times = sqrt(num) + 1;
    for (int i = 2; i < times; i++) {
      if (num % i == 0)sum += i + num / i;
      if (sum > num)return false;
    }
    return sum == num;
  }
};

int main() {
  Solution solution;
  solution.checkPerfectNumber(1);

  return 0;
}