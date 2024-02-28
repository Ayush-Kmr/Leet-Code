/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                isCycle = true;
                break ;
            }
        }
        if(isCycle == false) return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};