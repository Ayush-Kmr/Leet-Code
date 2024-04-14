class Solution {
public:
    int cnt=0;
 // int count(TreeNode* root,int &cnt){
 //     if(root==NULL){
 //         return cnt;
 //     }
 //     cnt++;
 //     count(root->left,cnt);
 //     count(root->right,cnt);
 //     return cnt;
 // }
    int countNodes(TreeNode* root) {
      if(root==NULL){
         return cnt;
     }
     cnt++;
     countNodes(root->left);
     countNodes(root->right);
     return cnt;
        
    }
};