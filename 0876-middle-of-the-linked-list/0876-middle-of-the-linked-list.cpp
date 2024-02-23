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
//     First Approach
    // if (!head || !head->next) return head;
    // int n = 0;
    // ListNode* curr = head;
    // while (curr) {
    //     curr = curr->next;
    //     n++;
    // }
    // int count = 0;
    // curr = head;
    //     while (count != (n / 2)) {
    //         curr = curr->next;
    //         count++;
    //     }
    //     return curr;
    
//     Optimal Approach
    ListNode* slow =head;
    ListNode* fast =head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
};