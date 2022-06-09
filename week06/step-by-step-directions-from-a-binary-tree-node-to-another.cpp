// TC: O(N), where N = number of nodes in the binary tree
// SC: O(N)
class Solution {
private:
    TreeNode* getLCA(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        if(root->val == start || root->val == dest) return root;
        
        auto L = getLCA(root->left, start, dest);
        auto R = getLCA(root->right, start, dest);
        if(L && R) return root;
        
        return L ? L : R;
    }
    
    bool findPath(TreeNode* root, int &target, string &path) {
        if(!root) return false;
        if(root->val == target) return true;
        
        path.push_back('L');
        if(findPath(root->left, target, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if(findPath(root->right, target, path)) return true;
        path.pop_back();
        
        return false;
    } 
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lca = getLCA(root, startValue, destValue);
        string pathToRoot(""), pathFromRoot("");
        
        findPath(lca, startValue, pathToRoot);
        findPath(lca, destValue, pathFromRoot);
        
        for(auto &ch : pathToRoot) ch = 'U';
        
        return pathToRoot + pathFromRoot;
    }
};