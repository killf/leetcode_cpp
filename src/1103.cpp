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


/*数学问题*/
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> result(num_people);

    int n = sqrt(candies * 2 + 0.25) - 0.5;
    int m = n / num_people;
    int k = candies;

    for (int i = 0; i < num_people; i++) {
      result[i] = (i + 1) * m + m * (m - 1) / 2 * num_people;
      k -= result[i];
    }

    n = m * num_people + 1;
    for (int i = 0; i < num_people; i++) {
      if (n > k) {
        result[i] += k;
        break;
      } else {
        result[i] += n;
        k -= n;
        n++;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  auto r = solution.distributeCandies(800, 40);
  return 0;
}