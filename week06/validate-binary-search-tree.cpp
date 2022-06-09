// TC: O(N), where N = number of nodes
// SC: O(H), where H = depth of recursion call
class Solution {
private: 
    bool validateBST(TreeNode* root, long long L, long long R) {
        if(!root) return true;
        auto val = root->val;
        if(val >= R || val <= L) return false;
        return validateBST(root->left, L, val) && validateBST(root->right, val, R);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }
};