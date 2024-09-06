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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy; 
        ListNode* curr = head;
        while (curr) {
            if (numsSet.find(curr->val) == numsSet.end()) {
                ans->next = curr;  
                ans = ans->next; 
            }
            curr = curr->next;  
        }
        ans->next = NULL;  
        ListNode* result = dummy->next; 
        delete dummy;
        return result;
    }
};