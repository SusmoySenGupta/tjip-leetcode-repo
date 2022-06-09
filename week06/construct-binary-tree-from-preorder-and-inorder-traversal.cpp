// TC: O(logN), where N = number of nodes
// SC: O(N)
class Solution {
private:
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int L, int R, int &pos, unordered_map<int, int> &inorder_pos) {
        if(L > R) return NULL;
        auto curr_root = new TreeNode(preorder[pos++]);
        int M = inorder_pos[curr_root->val];
        curr_root->left = constructTree(preorder, inorder, L, M-1, pos, inorder_pos);
        curr_root->right = constructTree(preorder, inorder, M+1, R, pos, inorder_pos);
        return curr_root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        unordered_map<int, int> inorder_pos;
        for(int i = 0; i < inorder.size(); i++) {
            inorder_pos[inorder[i]] = i;
        }
        auto root = constructTree(preorder, inorder, 0, preorder.size() - 1, pos, inorder_pos);
        return root;
    }
};