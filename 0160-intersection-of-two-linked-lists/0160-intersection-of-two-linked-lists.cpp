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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        ListNode* ans=NULL;
        while(curr1!=NULL){
            curr1->val*=-1;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            if(curr2->val<0){
              curr2->val*=-1;
             if(ans==NULL){ans=curr2;}
            }
            curr2=curr2->next;
        }
        curr1=headA;
        while(curr1!=NULL){
            if(curr1->val<0){
            curr1->val*=-1;}
            curr1=curr1->next;
        }
        return ans;
    }
};