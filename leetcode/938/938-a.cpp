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
            if(root->left != nullptr){
                q.push(root->left);
            }
            if(root->right != nullptr){
                q.push(root->right);
            }
        } 
        return ans;
    }
};