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
        queue<TreeNode*> q;

        TreeNode* cur;
        q.push(root);
        while(q.empty() == false){
            cur = q.front();q.pop();
            if(cur == nullptr){
                return nullptr;
            }
            if(val > cur->val){
                q.push(cur->right);
            } else if (val < cur->val){
                q.push(cur->left);
            } else {
                return cur;
            }
        }
            
        return root;
    }
};