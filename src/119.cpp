#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> v(rowIndex + 1);
    v[0] = 1;
    for (int n = 1; n <= rowIndex; n++) {
      for (int i = n; i > 0; i--) {
        v[i] += v[i - 1];
      }
    }

    return v;
  }
};

int main() {
  Solution solution;
  auto v = solution.getRow(3);
  return 0;
}