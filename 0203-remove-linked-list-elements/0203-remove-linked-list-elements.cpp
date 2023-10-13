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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* temp=head;
        head=NULL;
        while(temp!=NULL){
            
            if(temp->val!=val)
            {
                if(head==NULL){
                    head=temp;
                    curr=temp;
                }
                else
                {curr->next=temp;
                curr=curr->next;}
            }
            temp=temp->next;
        }
        curr->next = NULL;
        return head;
    }
};