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