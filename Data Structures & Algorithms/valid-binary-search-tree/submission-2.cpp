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
    bool isValidBST(TreeNode* root, int low = INT_MIN, int high = INT_MAX) {
        if (!root)
            return true;
        if (root->val >= high || root->val <= low)
            return false;
        return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
    }
};
