#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> split(const string &s, char c) {
        vector<string> result;

        stringstream ss;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != c)ss << s[i];
            else {
                string t = ss.str();
                if (!t.empty())result.push_back(t);
                ss.str("");
            }
        }

        result.push_back(ss.str());
        return result;
    }

    bool wordPattern(const string &pattern, const string &s) {
        auto ss = split(s, ' ');
        if (ss.size() != pattern.size())return false;
        if (s.empty())return true;

        string m[26];
        for (int i = 0; i < ss.size(); i++) {
            int a = pattern[i] - 'a';
            auto b = ss[i];

            if (m[a].empty()) {
                for (int j = 0; j < 26; j++)if (m[j] == b)return false;
                m[a] = b;
            } else {
                if (m[a] != b)return false;
                for (int j = 0; j < 26; j++)if (m[j] == b && a != j)return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    solution.wordPattern("abba", "dog cat cat dog");
    return 0;
}