// TC: O(N), where N = number of nodes in a binary tree
// SC: O(H), where H = depth of recursion call
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        
        return max(left_max, right_max) + 1;
    }
};