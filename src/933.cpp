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

using namespace std;

class RecentCounter {
public:
  RecentCounter() {}

  int ping(int t) {
    queue.push_back(t);
    while (queue.front() < t - 3000) queue.pop_front();
    return queue.size();
  }

private:
  list<int> queue;
};
