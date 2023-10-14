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
     ListNode* curr;
    bool solve (ListNode* head)
    {
        if(!head)return 1;
     bool b=solve(head->next);
       bool c= curr->val==head->val && b;
        curr=curr->next;
       
           return c;
    }
    bool isPalindrome(ListNode* head) {
        curr=head;
     return solve(head);
    }
};