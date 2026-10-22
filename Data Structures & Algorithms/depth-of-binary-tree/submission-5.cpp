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

 // stack
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            size_t s = q.size();
            while(s--){
                auto node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            lvl++;
        }
        return lvl;
    }
};
