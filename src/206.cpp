#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode n(-1);
    n.next = head;

    while (head && head->next) {
      auto *p1 = n.next, *p2 = head->next, *p3 = head->next->next;
      n.next = p2;
      p2->next = p1;
      head->next = p3;
    }

    return n.next;
  }
};