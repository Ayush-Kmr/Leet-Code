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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int i=0;
        while(curr){
            curr=curr->next;
            i++;
        }
        int mid= i/2;
        ListNode* temp = head;
        while(mid--){
            temp = temp->next;
        }
        return temp;
    }
};