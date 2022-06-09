// TC: O(N), where N = number of nodes
// SC: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()) {
            int len = nodes.size();
            for(int i = 0; i < len; i++) {
                auto U = nodes.front();
                nodes.pop();
                if(i + 1 < len) {
                    U->next = nodes.front();
                }
                if(U->left) nodes.push(U->left);
                if(U->right) nodes.push(U->right);
            }
        }

        return root;
    }
};