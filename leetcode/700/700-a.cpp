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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return nullptr;
        }
        if(val > root->val){
            root = searchBST(root->right, val);
        } else if(val < root->val){
            root = searchBST(root->left, val);
        } else {
            return root;
        }
        return root;
    }
};