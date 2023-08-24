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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode *currentNode = head;
       ListNode *temp=head;
        ListNode *ans=NULL;
        while(currentNode!=NULL){
          if(currentNode->val!=val){
              if(ans==NULL){
                temp=currentNode;
                ans=temp;
            }
               else {
                   temp->next=currentNode;
                     temp=currentNode;
                    }
            }
            currentNode=currentNode->next;
        }
      
        temp->next=NULL;
        return ans;
    }
};