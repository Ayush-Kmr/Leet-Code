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
    Node* level(Node* root){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            if(size == 0) return root;
            while(size>0){
                Node* temp;
                if(size > 1){
                    temp = q.front();
                    q.pop();
                    
                    Node* nextNode = q.front();
                    temp->next = nextNode;
                }
                else{
                    temp = q.front();
                    q.pop();
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
            root->next = NULL;
        }
        return root;
    }
    Node* connect(Node* root) {
        if(!root) return root;
        return level(root);
    }
};