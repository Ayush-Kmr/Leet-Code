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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
//         Recursive 
        // head->next = deleteDuplicates(head->next);
        // return (head->val == head->next->val) ? head->next : head;
        
//         Iterative
        ListNode* curr = head;
        while(curr->next){
            if(curr->val == curr->next->val){
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete(toDelete);
            }
            else{
            curr = curr->next;
            }
        }
        return head;
    }
};