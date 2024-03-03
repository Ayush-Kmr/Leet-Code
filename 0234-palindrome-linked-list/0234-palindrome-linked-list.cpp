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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
//         Middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
//         Reverse the list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* forward = NULL;
        while(curr && curr->next){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
//         Edge Case
        if(curr) curr->next = prev;
        
//         Checking the value
        fast = head;
        while(fast && curr){
            if(fast->val != curr->val) return false;
            fast = fast->next;
            curr = curr->next;
        }
        return true;
    }
};