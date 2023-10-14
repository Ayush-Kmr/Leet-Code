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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head || r==1 )
            return head;
        ListNode*ans= reverseBetween(head->next,l-1,r-1);
        if(l<=1)
       { ListNode* temp=head->next->next;
        head->next->next=head;
        head->next=temp;
        return ans;}
        head->next=ans;
        return head;
        
        
        
    }
};