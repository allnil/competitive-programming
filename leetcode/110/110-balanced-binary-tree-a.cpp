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
const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();


int dfs(TreeNode* node) {
    if(node == nullptr) {
        return 0;
    }

    int left_height = dfs(node->left);
    if(left_height == -1) {
        return -1;
    }    
    int right_height = dfs(node->right);
    if(right_height == -1) {
        return -1;
    }

    if(abs(left_height - right_height) > 1){
        return -1;
    }
    return max(left_height,right_height) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left_height = dfs(root->left);
        int right_height = dfs(root->right);
        if(left_height == -1 || right_height == -1){
            return false;
        }
        if(abs(left_height - right_height) > 1){
            return false;
        }

        return true; 
    }
};