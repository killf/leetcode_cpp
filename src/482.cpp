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
#include <cmath>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stringstream ss;
        int k = K;
        for (int i = S.size() - 1; i >= 0; i--) {
            char c = S[i];
            if (c == '-')continue;
            c = toupper(c);
            ss << c;
            if (--k == 0) {
                ss << "-";
                k = K;
            }
        }

        string s = ss.str();
        reverse(s.begin(), s.end());

        if (s[0] == '-') s.erase(0, 1);
        return s;
    }
};

int main() {
    string s = "12345";
    s.erase(0, 1);

    return 0;
}
