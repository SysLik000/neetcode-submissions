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


// stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node) {
                std::swap(node->right, node->left);
                st.push(node->right);
                st.push(node->left);
            }
        }
        return root;
    }
};
