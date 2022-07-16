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
// TC: O(N), where N = number of nodes
// SC: O(H), where H = depth of recursion call
class Solution {
private:
    int getMaxSum(TreeNode* root, int &maxSum) {
        if(!root) return 0;
        
        int L = max(0, getMaxSum(root->left, maxSum));
        int R = max(0, getMaxSum(root->right, maxSum));
        
        int val = root->val;
        int maxVal = max(L, R);
        
        maxSum = max(maxSum, val + L + R);
        return val + max(0, maxVal);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getMaxSum(root, maxSum);
        return maxSum;
    }
};