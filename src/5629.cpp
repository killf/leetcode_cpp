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

class Solution {
public:
  string reformatNumber(string number) {
    stringstream ss;
    for (auto c:number)if (isdigit(c))ss << c;
    number = ss.str();
    int size = number.size();

    ss.str("");
    int i = 0;
    for (; i < size - 4; i += 3) {
      if (i < size) ss << number[i];
      if (i + 1 < size)ss << number[i + 1];
      if (i + 2 < size)ss << number[i + 2];
      if (i < size - 1)ss << '-';
    }

    int d = size - i;
    if (d == 4) ss  << number[i] << number[i + 1] << "-" << number[i + 2] << number[i + 3];
    else if (d > 0) {
      for (; i < size; i++)ss << number[i];
    }

    return ss.str();
  }
};

int main() {
  string number = "123 4-5678";

  Solution solution;
  auto ret = solution.reformatNumber(number);
  return 0;
}