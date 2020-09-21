#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int c = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int s = digits[i] + c;
      c = s / 10;
      s = s % 10;

      digits[i] = s;
      if (c == 0)break;
    }

    if (c != 0)digits.insert(digits.begin(), c);
    return digits;
  }
};

int main(){
  Solution solution;
  vector<int> digits={1,2,3};
  vector<int> out = solution.plusOne(digits);
  cout << "Hello,world" << endl;
}