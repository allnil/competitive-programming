const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;

        while(root != nullptr || !s.empty()) {
            while(root != nullptr){
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();
            ans.push_back(root->val);
            root = root->right;
        }

        return ans;  
    }
};