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

using namespace std;

class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    if (typed.size() < name.size())return false;

    int i = 0, j = 0;
    while (!(i == name.size() && j == typed.size())) {
      if (i < name.size() && j < typed.size() && name[i] == typed[j]) {
        i++;
        j++;
      } else if (i - 1 >= 0 && i - 1 < name.size() && j < typed.size() && name[i - 1] == typed[j]) {
        j++;
      } else return false;
    }

    return true;
  }
};

int main() {
  string name = "alex";
  string typed = "aaleex";

  Solution solution;
  auto ret = solution.isLongPressedName(name, typed);
  return 0;
}