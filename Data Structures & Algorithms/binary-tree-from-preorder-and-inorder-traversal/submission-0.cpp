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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        auto m_inorder = std::find(inorder.begin(), inorder.end(), root->val);
        
        vector<int> l_inorder(inorder.begin(), m_inorder);
        vector<int> r_inorder(m_inorder + 1, inorder.end());

        auto left_size = m_inorder - inorder.begin();
        vector<int> l_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> r_preorder(preorder.begin() + 1 + left_size, preorder.end());


        root->left = buildTree(l_preorder, l_inorder);
        root->right = buildTree(r_preorder, r_inorder);

        return root;
    }
};
