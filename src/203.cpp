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
        ListNode *p = head, *prev = nullptr;
        while (p) {
            if (p->val == val) {
                if (prev) {
                    prev->next = p->next;
                    p = p->next;
                } else {
                    head = p = p->next;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};
