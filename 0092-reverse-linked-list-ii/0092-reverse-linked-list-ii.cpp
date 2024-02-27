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
    ListNode* temp=NULL;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right == 1){
            temp=head->next;
            return head;
        }
        ListNode *ans = reverseBetween(head->next, left-1, right-1);
        if(left<=1){
            head->next->next=head;
            head->next=temp;
            return ans;
        }
        head->next = ans;
        return head;
    }
};