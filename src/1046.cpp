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

/*大顶堆->优先级队列*/
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> queue;
    for (auto stone:stones)queue.push(stone);

    while (queue.size() > 1) {
      auto a = queue.top();
      queue.pop();
      auto b = queue.top();
      queue.pop();

      a -= b;
      if (a > 0)queue.push(a);
    }

    return queue.top();
  }
};