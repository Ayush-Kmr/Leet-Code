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
    //     if(!head) return head;
    //     head->next = removeNthFromEnd(head->next, n);
    //     size++;
    //     if(size == n){
    //         return head->next;
    //     }
    //     return head;
    // }
    
//     Iterative Solution
     if (!head || n <= 0) return head; // Edge cases

    ListNode* slow = head;
    ListNode* fast = head;
    while(n--){
        fast = fast->next;
    }
    if(fast == NULL) return slow->next;
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }
};