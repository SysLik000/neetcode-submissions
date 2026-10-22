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

 // DFS - stack
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        stack<pair<TreeNode*, int>> st;
        int lvl = 1;
        st.push({root, lvl});
        while(!st.empty()){
            auto [node, node_lvl] = st.top();
            st.pop();
            if (node->left)
                st.push({node->left, node_lvl + 1});
            if (node->right)
                st.push({node->right, node_lvl + 1});
            lvl = max(lvl, node_lvl);
        }
        return lvl;
    }
};
