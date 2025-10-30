/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* solve(Node* root){
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* temp = q.front();
                q.pop();
                
                if (n > 0) temp->next = q.front();
                else temp->next = NULL;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            root->next = NULL;
        }
        return root;
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};