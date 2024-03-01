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
//         Middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
//         Reversed the list
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = slow;
        while(curr && curr->next){
             forward = curr->next;
             curr->next = prev;
             prev = curr;
             curr = forward;
        }
        if(curr!=NULL ) curr->next = prev;
        
//         Checked the bool
        fast = head;
        while(curr && fast){
            if(curr->val != fast->val){
                return false;
            }
            curr = curr->next;
            fast = fast->next;
        }
        return true;
    }
};