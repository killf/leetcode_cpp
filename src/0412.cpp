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
#include <iomanip>

using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> result;

    for (int i = 1; i <= n; i++) {
      if (i % 15 == 0) result.emplace_back("FizzBuzz");
      else if (i % 3 == 0)result.emplace_back("Fizz");
      else if (i % 5 == 0)result.emplace_back("Buzz");
      else result.emplace_back(to_string(i));
    }

    return result;
  }
};