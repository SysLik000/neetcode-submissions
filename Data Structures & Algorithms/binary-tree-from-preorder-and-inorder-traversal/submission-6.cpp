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
    using Boundaries = std::pair<int, int>;

    TreeNode* build(vector<int>& preorder, Boundaries preBoundaries, Boundaries inBoundaries) {
        auto [pre_l, pre_r] = preBoundaries;
        auto [in_l, in_r] = inBoundaries;

        if (pre_l > pre_r)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[pre_l]);
        int node_id = indexes[node->val];
        int l_size = node_id - in_l;

        node->left = build(preorder, {pre_l + 1, pre_l + l_size}, {in_l, node_id - 1} );
        node->right = build(preorder, {pre_l + l_size + 1, pre_r}, {node_id + 1, in_r} );
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        for(int i = 0; i < inorder.size(); i++)
            indexes[inorder[i]] = i;

        return build(preorder, {0, preorder.size() - 1}, {0, inorder.size() - 1});
    }
};
