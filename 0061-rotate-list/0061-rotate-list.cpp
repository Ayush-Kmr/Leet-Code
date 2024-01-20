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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next )return head;
        int n =0;
        ListNode* curr =head;
        while(curr){
            curr=curr->next;
            n++;
        }
        k = k%n;
        if(k==0)return head;
        int count = n-k-1;
        ListNode* tail = head;
        curr=head;
        while(count--){
            
             curr=curr->next;
        }
        tail=curr->next;
        curr->next=NULL;
        cout<<curr->val;
        curr=tail;
         while(curr && curr->next){
            curr=curr->next;
            n++;
        }
        curr->next=head;
        return tail;
    }
};