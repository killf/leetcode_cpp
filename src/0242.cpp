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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())return false;

        int m[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            m[s[i] - 'a']++;
            m[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (m[i] != 0)return false;
        }

        return true;
    }
};