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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* carry = new ListNode(0);
        ListNode* ans=l1;
        ListNode* prev=l1;
        while(l1 && l2){
            int x= l1->val + l2->val +carry->val;
            l1->val=x%10;
            carry->val=x/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL) prev->next=l2;
        else l2=l1;
        while(l2){
            int x=l2->val +carry->val;
            l2->val=x%10;
            carry->val=x/10;
            prev=l2;
            l2=l2->next;
        }
        if(carry->val!=0){
            prev->next=carry;
            carry->next=NULL;
        }
        return ans;
    }
};