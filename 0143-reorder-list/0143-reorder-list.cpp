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
    ListNode* reverse(ListNode* curr){
        if(!curr || !curr->next) return curr; 
        ListNode* temp = reverse(curr->next);
        curr->next->next=curr;
        curr->next=NULL;
        
        return temp;
    }
    void reorderList(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode* prev;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        if(!fast) slow =prev;
        ListNode* temp = reverse(slow);
        ListNode* curr =head;
        while(curr ){
            ListNode* cf = curr->next;
            ListNode* tf = temp->next;
            curr->next=temp;
            temp->next=cf;
            temp=tf;
            curr=cf;
        }
    }
};