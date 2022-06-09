// TC: O(N), where N = size of the array
// SC: O(logN)
class Solution {
private:
    TreeNode* constructBST(vector<int> &nums, int L, int R) {
        if(L > R) return NULL;
        int mid = L + (R-L)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructBST(nums, L, mid-1);
        root->right = constructBST(nums, mid+1, R);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size()-1);
    }
};