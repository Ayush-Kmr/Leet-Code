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
    bool isPalindrome(ListNode* head) {
       // return NULL;
        ListNode* curr=head;
        vector<int>v;
        while(curr)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        int l=0;
        int h=v.size()-1;
        
        while(l<h)
            if(v[l++]!=v[h--])return 0;
        return 1;
    }
};