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
    ListNode* curr = NULL;
    bool isPalindrome(ListNode* head) {
        if(curr==NULL)curr=head;
        if(head==NULL) return 1;        
        bool ans = isPalindrome(head->next) && curr->val == head->val;
        curr = curr->next;
        return ans;
    }
};