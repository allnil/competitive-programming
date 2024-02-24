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
    int sum = 0;

    void traverse(TreeNode* node) {
        if (node == nullptr) return;

        traverse(node->right);

        sum += node->val;
        node->val = sum;

        traverse(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};