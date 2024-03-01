class Solution {
public:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSortedList(ListNode* p, ListNode* q) {
        if (!p || !q) {
            return (p == NULL) ? q : p;
        }
        ListNode* curr = new ListNode(0);
        ListNode* ans = curr;
        while (p && q) {
            if (p->val < q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (p || q) {
            curr->next = (p != NULL) ? p : q;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = middle(head);
        ListNode* newhead = mid->next;
        mid->next = NULL;

        ListNode* left_half = sortList(head);
        ListNode* right_half = sortList(newhead);

        return mergeSortedList(left_half, right_half);
    }
};
