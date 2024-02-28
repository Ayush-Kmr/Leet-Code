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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        map<int,int>freq;
        ListNode* curr = head;
        while(curr){
            freq[curr->val]++;
            curr = curr->next;
        }
        // cout<<freq[1];
        ListNode* temp = head;
        ListNode* ans = head;
        for(auto &pair:freq){
            if(pair.second == 1)
              {
                temp->val = pair.first;
                ans=temp;
                temp = temp->next;
            }
            }
       
        if(temp==head)return NULL;
        ans->next = NULL;
        return head;
    }
};