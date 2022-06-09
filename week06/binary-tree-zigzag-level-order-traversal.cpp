// TC: O(N), where N = number of nodes
// SC: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> zigzags;
        queue<TreeNode*> Q;
        int level = 0;
        
        Q.push(root);
        
        while(!Q.empty()) {
            int len = Q.size();
            vector<int> zigzag(len);
            
            for(int i = 0; i < len; i++) {
                auto U = Q.front();
                Q.pop();
                if(U->left) Q.push(U->left);
                if(U->right) Q.push(U->right);
                
                int pos = level%2 ? (len-i-1) : i;
                zigzag[pos] = U->val;
            }
            zigzags.push_back(zigzag);
            level++;
        }
        
        return zigzags;
    }
};