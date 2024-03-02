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
    int size(ListNode* curr){
        int s=0;
        while(curr){
        curr = curr->next;
        s++;
        }
        return s;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* curr = head;
        ListNode* head1;
        int n = size(head);
        int starting = k%n;
        starting = n - starting;
        if(n==1 || starting == n)return head;
        while(--starting){
            curr =curr->next;
        }
        head1 = curr->next;
        curr->next = NULL;
        ListNode* temp = head1;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return head1;
    }
};