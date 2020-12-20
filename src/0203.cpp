#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode node(-1);
        node.next = head;

        ListNode *p = &node;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else p = p->next;
        }

        return node.next;
    }
};
