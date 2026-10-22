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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});
        while (!st.empty()){
            auto [p1, q1] = st.top();
            st.pop();
            if (p1 == q1)
                continue;
            if (!p1 || !q1 || p1->val != q1->val)
                return false;
            st.push({p1->left, q1->left});
            st.push({p1->right, q1->right});
        }
        
        return true;
    }
};
