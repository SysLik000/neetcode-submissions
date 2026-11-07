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

class Codec {
public:
    const string null = "NULL";
    const char sep = ',';
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return null;
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) {
                res += null + sep;
            } else {
                res += to_string(node->val) + sep;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        if(!getline(ss, val, sep) || val == null)
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!getline(ss, val, sep))
                break;
            if (val != null) {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            if(!getline(ss, val, sep))
                break;
            if (val != null) {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
