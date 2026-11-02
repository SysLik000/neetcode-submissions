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
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;

        size_t size = preorder.size();
        TreeNode dummy;
        TreeNode *curr = &dummy;
        for(int i = 0, j =0; i < size && j < size;){
            curr->right = new TreeNode(preorder[i], nullptr, curr->right);
            curr = curr->right;
            for(++i; i < size && curr->val != inorder[j]; ++i){
                curr->left = new TreeNode(preorder[i], nullptr, curr);
                curr = curr->left;
            }
            j++;
            while(curr->right && j < size && curr->right->val == inorder[j]){
                TreeNode* prev = curr->right;
                curr->right = nullptr;
                curr = prev;
                j++;
            }   
        }

        return dummy.right;
    }
};
