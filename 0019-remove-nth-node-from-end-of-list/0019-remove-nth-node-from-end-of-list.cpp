/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int size =0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         Recursive Solution
    //     if(!head) return head;
    //     head->next = removeNthFromEnd(head->next, n);
    //     size++;
    //     if(size == n){
    //         return head->next;
    //     }
    //     return head;
    // }
    
//     Iterative Solution
     if (!head || n <= 0) return head; // Edge cases

    // Initialize two pointers
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (!fast) return head; // Invalid n
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    ListNode* prev = nullptr;
    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from the end
    if (prev) prev->next = slow->next;
    else head = slow->next; // If removing the head

    delete slow;
    return head;
}

};