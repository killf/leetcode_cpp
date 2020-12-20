#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0, low = 0, high = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[low] > prices[i]) {
        low = i;
        if (high < low)high = low;
        profit = max(profit, prices[high] - prices[low]);
      }

      if (prices[high] < prices[i]) {
        high = i;
        profit = max(profit, prices[high] - prices[low]);
      }
    }
    return profit;
  }
};

