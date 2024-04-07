class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool reverseLevel = false; // Flag to track if we need to reverse the level
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> zigzag(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                int index = reverseLevel ? size - 1 - i : i; // Adjust index based on zigzag pattern
                
                zigzag[index] = temp->val;
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            ans.push_back(zigzag);
            reverseLevel = !reverseLevel; // Toggle the reverse flag for the next level
        }
        
        return ans;
    }
};
