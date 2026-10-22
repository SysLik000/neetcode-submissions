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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        auto right = root->right;
        auto left = root->left;

        if (right){
            invertTree(right);
        }
        if (left){
            invertTree(left);
        }
        
        root->right = left;
        root->left = right;
        return root;
    }
};
