class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
		
        while (!q.empty()){ 
            vector<int> lvl,srtlvl;
            int size= q.size();
            for (int i=0; i<size; i++){
                TreeNode* node= q.front();
                lvl.push_back(node->val);
                srtlvl.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
			
            sort(srtlvl.begin(),srtlvl.end());
            for (int i=0; i<lvl.size(); i++){
                if (srtlvl[i]!=lvl[i]){
                    swap(lvl[i],lvl[find(lvl.begin(),lvl.end(),srtlvl[i])-lvl.begin()]);
                    ans++;
                }
            }
        }
        return ans;
    }
};