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

using namespace std;


class Solution {
public:
  bool hasAlternatingBits(int n) {
    int m = n;
    m |= m >> 1;
    m |= m >> 2;
    m |= m >> 4;
    m |= m >> 8;
    m |= m >> 16;

    int m1 = (n >> 1) & n;
    int m2 = (n >> 1) | n;
    return (~m1 & m) == m2;
  }
};