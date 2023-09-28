class Solution {

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(true){
            if(root == nullptr){
                return root;
            } else if(high < root->val){
                root = root->left;
            } else if(root->val < low){
                root = root->right; 
            } else {
                break;
            }
        }
        TreeNode* parent = root;
        while(parent->left != nullptr){
            if(parent->left->val < low){
                parent->left = parent->left->right;
            } else {
                parent = parent->left;
            }
        }

        parent = root;
        while(parent->right != nullptr){
            if(high < parent->right->val){
                parent->right = parent->right->left;
            } else {
                parent = parent->right;
            }
        }
        return root;
    }
};