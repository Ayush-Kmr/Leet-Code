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
        ListNode* curr=head;
          ListNode* p=head;
          bool f=true;
          ListNode*H=NULL;
          if(head==NULL)
          return NULL;
       while(curr)
        {
            if(curr->val!=val)
              {    if(f)
                  {H=curr;
                  f=0;
                  p=curr;
              }
              else { p->next=curr;
                  p=curr;}
              }
            
              curr=curr->next;
        }
  p->next=NULL;
return H;
    }
};