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

/*博弈问题，关键点是找出递推关系，然后归纳总结+数学证明*/
class Solution {
public:
  bool divisorGame(int N) {
    return N % 2 == 0;
  }
};