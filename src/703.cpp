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


class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : max_size(k), size(0) {
    data = new int[k];
    for (auto n:nums)insert(n);
  }

  int add(int val) {
    insert(val);
    return top();
  }

private:
  void insert(int val) {
    if (size >= max_size) {
      if (val <= data[0])return;
      data[0] = val;
      shift_down();
    } else {
      data[size] = val;
      shift_up(size);
      size++;
    }
  }

  int top() {
    return data[0];
  }

  void shift_down() {
    int i = 0;
    while (i < size) {
      int l = 2 * i + 1, r = 2 * i + 2;

      /*没有子节点*/
      int &val = data[i];
      if (l >= size)return;

      /*只有左子节点*/
      int &left = data[l];
      if (r >= size) {
        if (val > left) swap(val, left);
        i = l;
        continue;
      }

      /*拥有两个子节点*/
      int &right = data[r];
      if (val <= left && val <= right)return;
      if (left < val && left <= right) {
        swap(val, left);
        i = l;
        continue;
      }
      if (right < val && right <= left) {
        swap(val, right);
        i = r;
        continue;
      }
    }
  }

  void shift_up(int i) {
    while (i > 0) {
      int p = (i - 1) / 2;
      if (data[p] <= data[i])return;

      swap(data[p], data[i]);
      i = p;
    }
  }

private:
  int *data;
  int size;
  int max_size;
};

int main() {
  int n = 3;
  vector<int> nums = {1, 1};
  vector<int> ops = {1, 1, 3, 3, 3, 4, 4, 4};

  KthLargest kthLargest(n, nums);
  for (auto op:ops) {
    cout << kthLargest.add(op) << endl;
  }

  return 0;
}