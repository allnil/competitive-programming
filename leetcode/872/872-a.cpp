const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();

class Solution {
    void dfs(TreeNode* node, vector<int>& res){
        if(node == nullptr){
            return;
        }
        if(node->left == nullptr && node->right == nullptr){
            res.push_back(node->val);
            return;
        }
        dfs(node->left, res);
        dfs(node->right, res);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        dfs(root1, res);
        vector<int> res2;
        dfs(root2, res2);
        if(res.size() != res2.size()){
            return false;
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i] != res2[i]){
                return false;
            }
        }
        return true;
    }
};