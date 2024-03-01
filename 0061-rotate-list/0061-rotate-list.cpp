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
    int size(ListNode* head){
        int size = 0;
        while(head){
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = size(head);
        int starting = k%n;
        starting = n - starting;
        if(n == 1 || starting == n) return head;
        
        ListNode* temp = head;
        ListNode* head2 = head;
        int j =0;
        while(temp){
            j++;
            if(j==starting){
                head2 = temp->next;
                temp->next = NULL;
            }
            temp = temp->next;
        }
        temp = head2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return head2;
    }
};