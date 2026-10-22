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
    int maxDepth(TreeNode* root, int lvl = 0) {
        if (!root)
            return lvl;
        lvl++;
        auto left_lvl = maxDepth(root->left, lvl);
        auto right_lvl = maxDepth(root->right, lvl);
        return max(left_lvl, right_lvl);
    }
};
