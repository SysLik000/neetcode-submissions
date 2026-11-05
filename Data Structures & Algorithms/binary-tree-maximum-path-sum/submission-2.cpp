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

class Solution {
private:
    int dfs(TreeNode* node, int& result) {
        if (!node)
            return 0;

        int left = max(0, dfs(node->left, result));
        int right = max(0, dfs(node->right, result));
        result = max(result, node->val + left + right);
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
};