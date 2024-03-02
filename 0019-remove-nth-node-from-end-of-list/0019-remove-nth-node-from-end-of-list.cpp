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
    int size =0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         Recursive Solution
        if(!head) return head;
        head->next = removeNthFromEnd(head->next, n);
        size++;
        if(size == n){
            return head->next;
        }
        return head;
    }
};