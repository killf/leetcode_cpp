#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

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
#include <set>
#include <list>
#include <cstring>
#include <bitset>

using namespace std;

vector<string> split(const string &s, char c) {
  vector<string> result;

  string t;
  for (auto k :s) {
    if (k == c) {
      if (!t.empty()) {
        result.push_back(t);
        t.clear();
      }
    } else t += k;
  }
  if (!t.empty())result.push_back(t);

  return result;
}

template<typename T1, typename T2=typename T1::value_type>
T2 reduce_sum(const T1 &list) {
  T2 sum = T2();
  for (const auto &iter:list)sum += iter;
  return sum;
}

template<typename T>
class Mat {
public:
  Mat(int row, int col, const T &value = T()) : row_(row), col_(col), data_(new T[row * col]) {
    for (int i = 0; i < row * col; i++)data_[i] = value;
  }

  T &operator()(int r, int c) {
    return data_[r * col_ + c];
  }

  const T &operator()(int r, int c) const {
    return data_[r * col_ + c];
  }

private:
  T *data_;
  int row_, col_;
};

#endif //LEETCODE_UTILS_H
