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
    std::unordered_map<int,int> indexes;

    TreeNode* build(vector<int>& preorder, int pre_l, int in_l, int size) {
        if (size <= 0)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[pre_l]);
        int node_id = indexes[node->val];
        int l_size = node_id - in_l;
        int r_size = size - l_size - 1;

        node->left = build(preorder, pre_l + 1, in_l, l_size);
        node->right = build(preorder, pre_l + l_size + 1, node_id + 1, r_size);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        for(int i = 0; i < inorder.size(); i++)
            indexes[inorder[i]] = i;
        TreeNode *root = build(preorder, 0, 0, preorder.size());
        indexes.clear();
        return root;
    }
};
