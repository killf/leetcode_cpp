#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <tuple>
#include <hash_map>

using namespace std;

struct MyHash {
    size_t
    operator()(tuple<char, char> k) const {
        return get<0>(k) * 10 + get<1>(k);
    }
};

class Solution {
private:
    __gnu_cxx::hash_map<tuple<char, char>, tuple<char, char>, MyHash> mul_table;
    __gnu_cxx::hash_map<tuple<char, char>, tuple<char, char>, MyHash> add_table;

public:
    Solution() {
        int s;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                s = i * j;
                mul_table[{i + '0', j + '0'}] = {char(s / 10) + '0', char(s % 10) + '0'};

                s = i + j;
                add_table[{i + '0', j + '0'}] = {char(s / 10) + '0', char(s % 10) + '0'};
            }
        }
    }

    inline tuple<char, char> mul(char a, char b) {
        return mul_table[{a, b}];
    }

    tuple<char, char> mul(char a, char b, char c) {
        auto s1 = mul(a, b);
        auto s2 = add(get<1>(s1), c);
        auto s3 = add(get<0>(s1), get<0>(s2));

        return {get<1>(s3), get<1>(s2)};
    }

    inline tuple<char, char> add(char a, char b) {
        return add_table[{a, b}];
    }

    tuple<char, char> add(char a, char b, char c) {
        auto s1 = add(a, b);
        auto s2 = add(get<1>(s1), c);
        auto s3 = add(get<0>(s1), get<0>(s2));

        return {get<1>(s3), get<1>(s2)};
    }

    string add(string a, string b) {
        if (a.size() < b.size()) swap(a, b);

        a = string(a.rbegin(), a.rend());
        b = string(b.rbegin(), b.rend());

        stringstream ss;

        char c = '0';
        int i = 0;
        for (; i < b.size(); i++) {
            auto s = add(a[i], b[i], c);

            c = get<0>(s);
            ss << get<1>(s);
        }

        while (c != '0' && i < a.size()) {
            auto s = add(a[i], c);

            c = get<0>(s);
            ss << get<1>(s);

            i += 1;
        }

        if (c != '0') {
            ss << c;
        } else {
            while (i < a.size())ss << a[i++];
        }

        string s = ss.str();
        return string(s.rbegin(), s.rend());
    }

    string multiply(string num1, char num2) {
        if (num1 == "0" || num2 == '0')return "0";
        stringstream ss;

        char c = '0';
        for (int i = num1.size() - 1; i >= 0; i--) {
            char a = num1[i];
            auto s = mul(a, num2, c);

            c = get<0>(s);
            ss << get<1>(s);
        }

        if (c != '0') ss << c;

        string s = ss.str();
        return string(s.rbegin(), s.rend());
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        if (num1.size() < num2.size()) swap(num1, num2);

        string result = "0";
        for (int i = 0; i < num2.size(); i++) {
            string tmp = multiply(num1, num2[num2.size() - 1 - i]);
            for (int j = 0; j < i; j++)tmp += "0";
            result = add(result, tmp);
        }

        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.multiply("123", "456") << endl;
    return 0;
}