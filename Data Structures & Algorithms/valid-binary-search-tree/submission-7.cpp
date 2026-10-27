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


// recursive
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        queue<tuple<TreeNode*,int, int>> q;
        q.push({root, INT_MIN, INT_MAX});
        while(!q.empty()){
            auto [node, low, high] = q.front();
            q.pop();

            if (node->val <= low || node->val >= high)
                return false;
            
            if (node->left)
                q.push({node->left, low, node->val});
            if (node->right)
                q.push({node->right, node->val, high});
        }
        return true;
    }
};
