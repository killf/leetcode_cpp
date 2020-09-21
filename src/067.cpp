#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>

using namespace std;

class Solution {
public:
  tuple<char, char> add(char a, char b, char c) {
    if (a == '0' && b == '0' && c == '0') return {'0', '0'};
    else if (a == '0' && b == '0' && c == '1') return {'0', '1'};
    else if (a == '0' && b == '1' && c == '0') return {'0', '1'};
    else if (a == '1' && b == '0' && c == '0') return {'0', '1'};
    else if (a == '1' && b == '1' && c == '0') return {'1', '0'};
    else if (a == '1' && b == '0' && c == '1') return {'1', '0'};
    else if (a == '0' && b == '1' && c == '1') return {'1', '0'};
    else return {'1', '1'};
  }

  string addBinary(string a, string b) {
    if (a.size() < b.size())swap(a, b);

    a = string(a.rbegin(), a.rend());
    b = string(b.rbegin(), b.rend());

    stringstream ss;

    char c = '0';
    int i = 0;
    for (; i < b.size(); i++) {
      auto[d, r] = add(a[i], b[i], c);

      ss << r;
      c = d;
    }

    for (; i < a.size(); i++) {
      auto[d, r] = add(a[i], '0', c);
      ss << r;
      c = d;
    }

    if (c != '0')ss << c;

    string s = ss.str();
    return string(s.rbegin(), s.rend());
  }
};

int main() {
  Solution solution;
  cout << solution.addBinary("100", "110010") << endl;
}