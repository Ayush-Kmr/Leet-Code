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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeSortedList(ListNode* p, ListNode* q){
        if(!p || !q){
            return (p==NULL) ? q : p;
        }
        ListNode* curr = new ListNode(0);
        ListNode* ans = curr;
        while(p && q){
            if(p->val <= q->val){
                curr->next = new ListNode(p->val);
                curr = curr->next;
                p = p->next;
            }
            else{
                curr->next = new ListNode(q->val);
                curr = curr->next;
                q = q->next;
            }
        }
        if(p || q){
            curr->next = (p==NULL) ? q : p;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = middle(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        
        ListNode* left_half = sortList(head);
        ListNode* right_half = sortList(head2);
        
        return mergeSortedList(left_half, right_half);
    }
};