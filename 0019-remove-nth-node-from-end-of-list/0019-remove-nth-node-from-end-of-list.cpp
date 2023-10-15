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
    int size=0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        head->next=removeNthFromEnd(head->next,n);
        size++;
        return size==n?head->next:head;
    }
};