const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {        
        while(root != nullptr){
            if(val > root->val){
                root = root->right;
            } else if (val < root->val){
                root = root->left;
            } else {
                return root;
            }
        }
            
        return nullptr;
    }
};