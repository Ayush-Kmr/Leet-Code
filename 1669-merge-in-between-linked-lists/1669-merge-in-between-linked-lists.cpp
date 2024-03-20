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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        int count =0;
        curr = list1;
        ListNode* temp;
        while(count!=a && curr->next){
            temp = curr;
            curr = curr->next;
            count++;
        }
        curr = temp->next;
        while(count!=b && curr->next){
            curr = curr->next;
            count++;
        }
        temp->next = list2;
        while(list2->next){
            list2=list2->next;
        }
        list2->next = curr->next;
        return list1;
    }
};