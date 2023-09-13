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
    int ans = 0;
    void dfs(TreeNode* node, int depth){
        if(node->left == nullptr && node->right == nullptr){
            ans = min(ans, depth);
            return;
        }
        if(node->left != nullptr) dfs(node->left, depth + 1);
        if(node->right != nullptr) dfs(node->right, depth + 1);
    }
public:
    int minDepth(TreeNode* root) {
       ans = 1e9;
       if(root == nullptr){
           return 0;
       }
       dfs(root, 1);
       return ans; 
    }
};