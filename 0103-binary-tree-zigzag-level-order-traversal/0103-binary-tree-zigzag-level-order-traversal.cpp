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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level =1;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            if(size == 0) return ans;
            vector<int>zigzag;
            while(size>0){
                TreeNode* temp = q.front();
                q.pop();
                zigzag.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
            if(level%2 == 0) reverse(zigzag.begin(),zigzag.end());
            ans.push_back(zigzag);
            level++;
        }
        return ans;
    }
};