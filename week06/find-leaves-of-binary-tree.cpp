// Name: Susmoy Sen Gupta
// TC: O(N), where N = number of nodes
// SC: O(N)
class Solution {
private:
    TreeNode* getLeaves(TreeNode* root, vector<int> &curr_leaves) {
        if(!root) return NULL;
        if(!root->left && !root->right) {
            curr_leaves.push_back(root->val);
            return NULL;
        }
        root->left = getLeaves(root->left, curr_leaves);
        root->right = getLeaves(root->right, curr_leaves);
        return root;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> all_leaves;
        while(root) {
            vector<int> curr_leaves;
            root = getLeaves(root, curr_leaves);
            all_leaves.push_back(curr_leaves);
        }
        return all_leaves;
    }
};