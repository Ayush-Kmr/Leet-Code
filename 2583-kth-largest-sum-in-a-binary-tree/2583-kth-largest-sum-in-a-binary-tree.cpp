/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long res =0;
        if(!root) return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>ans;
        while(!q.empty()){
            long long size = q.size();
            long long sum =0;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        if(k>ans.size()) return -1;
       
        
        return ans[ans.size() - k];
    }
};