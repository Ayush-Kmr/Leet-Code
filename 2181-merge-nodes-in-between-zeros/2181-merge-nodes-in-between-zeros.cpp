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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = new ListNode(0);
        ListNode* ans = curr;
        int sum =0;  
        head = head->next;
        while(head){
            sum+= head->val;
            if((head->val) == 0){
                curr->next = new ListNode(sum);
                sum =0;
                curr = curr->next;
            }
            head = head->next;
        }
        return ans->next;
    }
};