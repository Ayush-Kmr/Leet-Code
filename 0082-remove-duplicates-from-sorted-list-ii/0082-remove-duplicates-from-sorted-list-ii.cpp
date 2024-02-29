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
        ListNode* temp =head;
        ListNode* ans = NULL;
        for(const auto &pair:freq){
            if(pair.second == 1){
                temp->val = pair.first;
                ans = temp;
                temp = temp->next;
            }
        }
        if(!ans) return ans;
        ans->next = NULL;
        return head;
    }
};