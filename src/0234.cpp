#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <hash_map>
#include <hash_set>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next)return true;

    ListNode *p1 = head, *p2 = head->next; // p1为左边链表的尾节点
    while (p2 && p2->next && p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    reverse(p1);

    ListNode *a = head, *b = p1->next;
    while (a != p1->next) {
      if (a->val != b->val)return false;
      a = a->next;
      b = b->next;
    }

    reverse(p1);
    return true;
  }

  void reverse(ListNode *head) {
    if (!head || !head->next)return;

    ListNode *p = head->next;
    while (p && p->next) {
      ListNode *p1 = head->next, *p2 = p->next, *p3 = p->next->next;

      head->next = p2;
      p2->next = p1;
      p->next = p3;
    }
  }
};