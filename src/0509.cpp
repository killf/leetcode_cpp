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
  int fib(int N) {
    if (N == 0)return 0;
    if (N == 1)return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= N; i++) {
      int c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};