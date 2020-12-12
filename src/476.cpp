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
    int findComplement(int num) {
        int flag = num;
        flag |= flag >> 1;
        flag |= flag >> 2;
        flag |= flag >> 4;
        flag |= flag >> 8;
        flag |= flag >> 16;
        return ~num & flag;
    }
};

void print(unsigned int n) {
    cout << setw(4) << n << ":";
    unsigned int flag = 1 << 31;
    for (int i = 0; i < 32; i++) {
        if (n & flag) cout << "1";
        else cout << "0";
        flag >>= 1;
    }
    cout << endl;
}


int main() {
    int num = 1 << 5;
    print(num);
    print((num = num | (num >> 1)));
    print((num = num | (num >> 2)));
    print((num = num | (num >> 4)));
    print((num = num | (num >> 8)));
    print((num = num | (num >> 16)));

    return 0;
}