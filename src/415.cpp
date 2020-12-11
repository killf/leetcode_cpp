#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

class Solution {
public:
  Solution() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int sum = i + j;
        int k1 = sum / 10;
        int k2 = sum % 10;
        m1[i][j] = '0' + (char) k1;
        m2[i][j] = '0' + (char) k2;
      }
    }
  }

  string addStrings(string num1, string num2) {
    if (num1.size() > num2.size())swap(num1, num2);

    string result;

    char c = '0';
    int s1 = num1.size(), s2 = num2.size();
    for (int i = 0; i < min(s1, s2); i++) {
      char a = num1[s1 - i - 1], b = num2[s2 - i - 1];
      auto[m, n]=add(a, b, c);
      result.insert(0, 1, n);
      c = m;
    }

    for (int i = 0; i < s2 - s1; i++) {
      char a = num2[s2 - s1 - i - 1];
      auto[m, n]=add(a, c);
      result.insert(0, 1, n);
      c = m;
    }

    if (c != '0')result.insert(0, 1, c);
    return result;
  }

  tuple<char, char> add(char a, char b, char c) {
    auto[i1, j1] = add(a, b);
    auto[i2, j2] = add(j1, c);
    auto[i3, j3] = add(i1, i2);
    return {j3, j2};
  }

  tuple<char, char> add(char a, char b) {
    int k1 = a - '0';
    int k2 = b - '0';
    return {m1[k1][k2], m2[k1][k2]};
  }

private:
  char m1[10][10];
  char m2[10][10];
};

int main() {
  Solution solution;
  auto v = solution.addStrings("1550", "96845612");
  return 0;
}