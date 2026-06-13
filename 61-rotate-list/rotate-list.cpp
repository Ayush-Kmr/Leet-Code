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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode * temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        k = k % n;
        k = n - k;
        if(n==1 || k == n || k==0) return head;
        temp = head;
        while(--k) temp = temp->next;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(newHead->next) newHead = newHead->next;
        newHead->next = head;
        return temp;
    }
};