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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>st;
        ListNode*temp = head;
        ListNode* lef = NULL;
        int count =0;
        while( temp!= NULL && count <left){
            lef = temp;
            temp = temp->next;
            count++;
        }
        int x = count;
        temp  = lef;
        st.push(lef->val);
        while(count<right){
            lef = lef->next;
            count++;
            st.push(lef->val);
        }
        while(!st.empty()){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
            x++;
            
        }
        return head;
    }
};