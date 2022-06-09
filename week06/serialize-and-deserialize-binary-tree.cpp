// TC: O(N), where N = number of nodes
// SC: O(N)
class Codec {
private:
    queue<string> getNodes(string &str) {
        queue<string> Q;
        string digit = "";
        for(auto &ch : str) {
            if(ch == ',') {
                Q.push(digit);
                digit.clear();
            } else {
                digit += ch;
            }
        }
        return Q;
    }
    
    TreeNode* constructTree(queue<string> &Q) {
        string node = Q.front();
        Q.pop();
        if(node == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(node));
        root->left = constructTree(Q);
        root->right = constructTree(Q);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes = getNodes(data);
        return constructTree(nodes);
    }
};