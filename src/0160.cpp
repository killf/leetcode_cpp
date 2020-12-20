#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//    int la = 0, lb = 0;
//    for (auto *a = headA; a; a = a->next)la++;
//    for (auto *b = headB; b; b = b->next)lb++;
//
//    for (; la > lb; headA = headA->next)la--;
//    for (; lb > la; headB = headB->next)lb--;
//
//    while (headA && headB) {
//      if (headA == headB)return headA;
//      headA = headA->next;
//      headB = headB->next;
//    }
//
//    return nullptr;
//  }
//};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;

    while (a || b) {
      if (a == b)return a;

      if (a) a = a->next; else a = headB;
      if (b)b = b->next; else b = headA;
    }

    return nullptr;
  }
};