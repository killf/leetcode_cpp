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
#include <bitset>
#include <set>

using namespace std;

inline string process(string &s) {
    stack<char> stack;
    for (auto c:s) {
        if (c == '#') {
            if (!stack.empty())stack.pop();
        } else stack.push(c);
    }

    stringstream ss;
    while (!stack.empty()) {
        ss << stack.top();
        stack.pop();
    }

    return ss.str();
}

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return process(S) == process(T);
    }
};