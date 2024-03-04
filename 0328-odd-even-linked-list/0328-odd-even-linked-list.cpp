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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int>v;
        ListNode* curr = head;
        while(curr->next){
            v.push_back(curr->val);
            curr = curr->next;
        }
        if(curr)v.push_back(curr->val);
        curr = head->next; 
        for(int i=2; i<v.size(); i++){
            if(i%2 == 0){
                curr->val = v[i];
                curr = curr->next;
            }
        }
         for(int i=1; i<v.size(); i++){
            if(i%2 != 0){
            curr->val = v[i];
            curr = curr->next;
            }
        }
        
        
       
        return head;
    }
};