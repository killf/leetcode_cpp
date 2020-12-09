#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *p1 = head, *p2 = head;

    int n = 0;
    while (p1 && p1->next && p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
      n += 1;

      if (p1 == p2)return true;
    }
    return false;
  }
};