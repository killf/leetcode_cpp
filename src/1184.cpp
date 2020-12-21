#include "utils.h"

/*遍历问题*/
class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    int sum = reduce_sum(distance);
    int n = 0;
    while (start != destination) {
      n += distance[start];
      start++;
      if (start >= distance.size())start = 0;
    }
    return min(n, sum - n);
  }
};