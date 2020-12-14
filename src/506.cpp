#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>

using namespace std;

struct Node {
  Node *next;
  int value;
  int index;
};

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    Node *head = new Node{.next=nullptr, .value=nums[0], .index=0};

    for (int i = 1; i < nums.size(); i++) {
      int n = nums[i];
      Node *p = head;
      if (n > head->value) {
        head = new Node{.next=p, .value=n, .index=i};
        continue;
      }

      for (; p->next; p = p->next) {
        if (n > p->next->value) break;
      }

      p->next = new Node{.next=p->next, .value=n, .index=i};
    }

    vector<string> result(nums.size());
    int rank = 1;
    for (Node *p = head; p; p = p->next, rank++) {
      switch (rank) {
        case 1:
          result[p->index] = "Gold Medal";
          break;
        case 2:
          result[p->index] = "Silver Medal";
          break;
        case 3:
          result[p->index] = "Bronze Medal";
          break;
        default:
          result[p->index] = to_string(rank);
          break;
      }
    }

    return result;
  }
};

int main() {
  map<int, int> m;
  m[3] = 1;
  m[4] = 2;
  m[1] = 3;

  for (auto it:m) {
    cout << it.first << "," << it.second << endl;
  }

  return 0;
}