#include "utils.h"

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

/*二进制问题*/
class Solution {
public:
  int getDecimalValue(ListNode *head) {
    int x = 0;
    while (head) {
      x <<= 1;
      x |= head->val;
      head = head->next;
    }
    return x;
  }
};