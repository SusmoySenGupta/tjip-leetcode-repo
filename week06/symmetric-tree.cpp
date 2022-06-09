 */
// TC: O(N), where N = number of nodes
// SC: O(H), where H = depth of recursion call
class Solution {
private:
    bool isSymmetricHelper(TreeNode* left_root, TreeNode* right_root) {
        if(!left_root || !right_root) return left_root == right_root;
        if(left_root->val != right_root->val) return false;
        
        bool left_ans = isSymmetricHelper(left_root->left, right_root->right);
        bool right_ans = isSymmetricHelper(left_root->right, right_root->left);
        
        return (left_ans && right_ans);
    }
public:
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
       return isSymmetricHelper(root->left, root->right); 
    }
};