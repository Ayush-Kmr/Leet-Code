class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;

        while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(isCycle == false){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};