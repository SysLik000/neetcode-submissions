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
private:
    bool isSame(TreeNode* r, TreeNode* s) {
        if (r == s)
            return true;
        
        if (!r || !s || r->val!=s->val)
            return false;

        return isSame(r->left, s->left) && isSame(r->right, s->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        if (root->val == subRoot->val && isSame(root, subRoot))
            return true;
     
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
