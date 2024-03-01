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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int size =0;
        while(curr){
            curr = curr->next;
            size++;
        }
        int li = size - k;
        ListNode* st = head;
        ListNode* ed = head;
        while(k>1){
            st = st->next;
            k--;
        }
        while(li>0){
            ed = ed->next;
            li--;
        }
        
        swap(st->val, ed->val);
        return head;
    }
};