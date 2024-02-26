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
    ListNode* reverseList(ListNode* head) {
//         Iterative Solution
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        
        while(curr){
            forward = curr->next;
            curr->next= prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        
//         Recursive Solution
//         if(!head || !head->next) return head;
//         ListNode *temp = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
        
//         return temp;
    }
};