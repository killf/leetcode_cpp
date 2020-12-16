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

using namespace std;

class Solution {
public:
  Solution() {
    vector<int> nums = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (auto n:nums)primes[n] = true;
  }

  int countPrimeSetBits(int L, int R) {
    int result = 0;
    bitset<32> b;
    for (int i = L; i <= R; i++) {
      b = i;
      if (primes[b.count()])result++;
    }
    return result;
  }

private:
  bool primes[33] = {};
};

int main() {
  bitset<32> b(3);
  cout << b.count() << endl;

  b = 1;
  cout << b.count() << endl;
  return 0;
}