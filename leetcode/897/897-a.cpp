class Solution {
public:
    TreeNode* prev = nullptr; 
    TreeNode* newRoot = nullptr; 

    void visit(TreeNode* node) {
        if (!node) return;
        visit(node->left); 
        
        if (prev) {
            prev->right = node; 
        } else {
            newRoot = node; 
        }
        node->left = nullptr; 
        prev = node; 
        
        visit(node->right); // Visit right subtree
    }

    TreeNode* increasingBST(TreeNode* root) {
        visit(root);
        return newRoot;
    }
};
