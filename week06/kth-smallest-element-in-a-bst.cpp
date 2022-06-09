// TC: O(N), where N = number of nodes
// SC: O(1)
class Solution {
private:
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return -1;
        
        int L = kthSmallest(root->left, k);
        k--;
        if(k == 0) return root->val;
        int R = kthSmallest(root->right, k);
        
        return max(L, R);
    }
};