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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,nullptr);
        int count = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        int bucketNodes = count/k;
        int extraNodes = count%k;
        
        ListNode* prev = nullptr;
        curr = head;
        for(int i=0; curr!=nullptr && i<k; i++){
            ans[i] = curr;
            for(int count = 1; count<=bucketNodes+(extraNodes>0 ? 1:0); count++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            extraNodes--;
        }
        return ans;
    }
};