#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int next(int n) {
        int sum = 0;
        while (n >= 10) {
            int v = n % 10;
            sum += v * v;
            n = n / 10;
        }
        sum += n * n;
        return sum;
    }

    bool has_cycle(int i) {
        return i == 4 || i == 16 || i == 20 || i == 37 || i == 42 || i == 58 || i == 89 || i == 145;
    }

    bool isHappy(int n) {
        while (true){
            if (n == 1)return true;
            if (has_cycle(n))return false;
            n = next(n);
        }
    }
};

vector<int> getHappyLists(Solution &solution, int n) {
    if (n == 1)return {};

    int a = n, b = n;
    do {
        a = solution.next(a);
        b = solution.next(solution.next(b));
        if (a == 1 || b == 1)return {};
    } while (a != b);

    vector<int> v;
    do {
        v.push_back(b);
        b = solution.next(b);
    } while (a != b);

    sort(v.begin(), v.end());
    return v;
}

void print(vector<int> &v) {
    for (auto i:v) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    Solution solution;
    for (int i = 2; i <= 243; i++) {
        auto v = getHappyLists(solution, i);
        print(v);
    }
    return 0;
}
