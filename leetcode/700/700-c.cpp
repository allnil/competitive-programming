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
        TreeNode* cur = root;
        
        while(cur != nullptr){
            if(val > cur->val){
                cur = cur->right;
            } else if (val < cur->val){
                cur = cur->left;
            } else {
                return cur;
            }
        }
            
        return nullptr;
    }
};