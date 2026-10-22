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

 // recurcive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        auto left_lvl = maxDepth(root->left);
        auto right_lvl = maxDepth(root->right);
        return 1 + max(left_lvl, right_lvl);
    }
};
