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
    int length(ListNode* head){
        int size = 0;
        while(head){
            head = head->next;
            size++;
        }
        return size;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || length(head) < k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = NULL;
        int i=0;
        while(curr && i < k){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            i++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};