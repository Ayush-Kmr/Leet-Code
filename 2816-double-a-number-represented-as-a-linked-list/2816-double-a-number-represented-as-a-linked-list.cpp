class Solution {
public:
    bool carry(ListNode* head){
        if (!head) return 0;
        bool c=carry(head->next);
        int x=head->val*2+c;
        bool c0=0;
        if (x>=10) x-=10, c0=1;
        head->val=x;
        return c0;
    }
    ListNode* doubleIt(ListNode* head) {
        if (carry(head)) head=new ListNode(1, head);
        return head;
    }
};