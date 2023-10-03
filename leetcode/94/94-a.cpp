const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    void dfs(TreeNode* node, vector<int> &ans){
        if(node == nullptr){
            return;
        }
        dfs(node->left, ans);
        ans.push_back(node->val);
        dfs(node->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        dfs(root, ans);
        return ans;      
    }
};