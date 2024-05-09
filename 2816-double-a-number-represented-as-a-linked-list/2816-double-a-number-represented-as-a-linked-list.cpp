class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = reverseList(head);
        ListNode* newHead = NULL; 
        ListNode* prev = NULL; 
        int carry = 0;

        while (curr) {
            int newVal = curr->val * 2 + carry;
            curr->val = newVal % 10;
            carry = newVal / 10;

            if (prev == NULL) {
                newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }

        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }

        return reverseList(newHead);
    }
};
