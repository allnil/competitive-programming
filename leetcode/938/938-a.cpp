const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        queue<TreeNode*> q; q.push(root);
        while(q.empty() == false){
            root = q.front(); q.pop();
            if(root->val >= low && root->val <= high){
                ans += root->val;
            }
            if(root->left != nullptr && root->val >= low){
                q.push(root->left);
            }
            if(root->right != nullptr && root->val <= high){
                q.push(root->right);
            }
        } 
        return ans;
    }
};