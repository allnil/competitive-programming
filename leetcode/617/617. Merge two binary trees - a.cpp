class Solution {

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        }  
        int res = 0;
        if(root1 != nullptr){
            res += root1->val;
        }
        if(root2 != nullptr){
            res += root2->val;
        }

        TreeNode* node = new TreeNode(res);

        node->left = mergeTrees(root1 == nullptr ? nullptr : root1->left, root2 == nullptr ? nullptr : root2->left);
        node->right = mergeTrees(root1 == nullptr ? nullptr : root1->right, root2 == nullptr ? nullptr : root2->right);
        return node;
    }
};