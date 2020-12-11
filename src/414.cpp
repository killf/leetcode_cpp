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

using namespace std;

template<typename T>
class MinHeap {
public:
  MinHeap(size_t max_size) : data(new T[max_size]), max_size(max_size), size(0) {}

  ~MinHeap() { delete[] data; }

  void insert(const T &value) {
    for (int i = 0; i < size; i++)if (data[i] == value)return;

    if (size >= max_size) {
      if (value > data[0]) {
        data[0] = value;
        sift_down();
      }
      return;
    }

    data[size] = value;
    sift_up(size);
    size++;
  }

  T top() {
    if (size >= max_size)return data[0];

    T max = data[0];
    for (int i = 1; i < size; i++) {
      if (max < data[i])max = data[i];
    }

    return max;
  }

private:
  void sift_up(size_t i) {
    while (i > 0) {
      auto &c = data[i];
      auto &p = data[(i - 1) / 2];
      if (p < c)return;

      swap(p, c);
      i = (i - 1) / 2;
    }
  }

  void sift_down() {
    size_t i = 0;
    while (i < size) {
      auto &root = data[i];
      if (2 * i + 2 < size) {
        auto &left = data[2 * i + 1];
        auto &right = data[2 * i + 2];
        if (root < left && root < right)return;

        if (left < right) {
          swap(root, left);
          i = 2 * i + 1;
        } else {
          swap(root, right);
          i = 2 * i + 2;
        }
      } else if (2 * i + 1 < size) {
        auto &left = data[2 * i + 1];
        if (root < left)return;

        swap(root, left);
        i = 2 * i + 1;
      } else return;
    }
  }

private:
  T *data;
  size_t max_size;
  size_t size;
};

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    MinHeap<int> heap(3);
    for (auto n:nums)heap.insert(n);

    return heap.top();
  }
};

int main() {
  vector<int> v = {5, 2, 4, 1, 3, 6, 0};

  Solution solution;
  auto r = solution.thirdMax(v);

  return 0;
}