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
// Author: Susmoy Sen Gupta
// TC: O(NlogN), where N = number of nodes
// SC: O(N)
class Solution {
public:
    map<int, map<int, vector<int>>> orderMP;
    
    void traverse(TreeNode* root, int row = 0, int col = 0) {
        if (!root) return;
        orderMP[col][row].push_back(root->val);
        traverse(root->left, row + 1, col - 1);
        traverse(root->right, row + 1, col + 1);
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root);
        for (auto &col : orderMP) {
            vector<int> tempResult;
            for (auto &row: col.second) {
              for (auto &node : row.second) {
                  tempResult.push_back(node);
              }  
            }
            result.push_back(tempResult);
        }
        return result;
    }
};