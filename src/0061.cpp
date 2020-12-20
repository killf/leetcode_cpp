struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next)return head;

        ListNode *p1, *p2;

        int len = 0;
        for (p1 = head; p1; p1 = p1->next, len++);

        k = k % len;
        for (p2 = p1 = head; k > 0; k--) {
            p2 = p2->next;
        }

        for (; p2->next; p1 = p1->next, p2 = p2->next);

        p2->next = head;
        head = p1->next;
        p1->next = nullptr;

        return head;
    }
};

