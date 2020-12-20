struct ListNode {
  int val;
  ListNode *next;

  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)return head;

    ListNode *p = head->next, *last = head;
    while (p) {
      if (last->val == p->val) {
        last->next = p->next;
        p = last->next;
      } else {
        p = p->next;
        last = last->next;
      }
    }
    return head;
  }
};