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
       ListNode *curr=headA;
         ListNode *ans=NULL;
        while(curr)
        {
            curr->val*=-1;
            curr=curr->next;
        }
        curr=headB;
        
         while(curr)
        { if(curr->val<0)
           { curr->val*=-1;
            if(!ans)ans=curr;
            }
        // cout<<curr->val<<" ";
            curr=curr->next;
        }
        curr=headA;
         while(curr)
        {  if(curr->val<0)
            curr->val*=-1;
            curr=curr->next;
        }
        return ans;
      

    }
};