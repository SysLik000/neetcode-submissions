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
        int max_lvl = 0;
        st.push({root, 1});
        while(!st.empty()){
            auto [node, lvl] = st.top();
            st.pop();
            if (node->left)
                st.push({node->left, lvl + 1});
            if (node->right)
                st.push({node->right, lvl + 1});
            max_lvl = max(lvl, max_lvl);
        }
        return max_lvl;
    }
};
