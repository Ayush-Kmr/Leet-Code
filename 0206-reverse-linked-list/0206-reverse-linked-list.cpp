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
    ListNode* reverseList(ListNode* head) {
        ListNode* currentNode = head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(currentNode!=NULL){
            forward=currentNode->next;
            currentNode->next=prev;
            prev=currentNode;
        
            currentNode=forward;
        }
        return prev;
    }
};