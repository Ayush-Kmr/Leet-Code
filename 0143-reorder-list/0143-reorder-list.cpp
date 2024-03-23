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
    ListNode* reverse(ListNode* curr){
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        if(!fast) slow =prev;
        ListNode* temp = reverse(slow);
        ListNode* curr = head;
        ListNode* rev = temp;
        while(curr){
            ListNode* currNext = curr->next;
            ListNode* revNext = rev->next;
            curr->next = rev;
            rev->next = currNext;
            curr = currNext;
            rev = revNext;
        }
    }
};