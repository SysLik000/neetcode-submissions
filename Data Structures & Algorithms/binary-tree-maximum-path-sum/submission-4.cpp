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
    int maxSum(TreeNode* root, int& res){
        if (!root)
            return 0;

        int l = max(maxSum(root->left, res), 0);
        int r = max(maxSum(root->right, res), 0);
        res = max(res, l + r + root->val);
        return root->val + max(l , r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSum(root, res);
        return res;
    }
};