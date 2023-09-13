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
class Solution {
public:
    int maxLevel;
    void dfs(vector<double>& ans, vector<double>& cnt, int level, TreeNode* node){
        if(node == nullptr){
            return;
        }
        if(ans.size() <= level){
            ans.push_back(0);
            cnt.push_back(0);
        }

        maxLevel = max(maxLevel, level);

        ans[level] += node->val;
        cnt[level] += 1;


        dfs(ans, cnt, level + 1, node->left);
        dfs(ans, cnt, level + 1, node->right);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        maxLevel = 0;
        vector<double> ans;    
        vector<double> cnt;
        dfs(ans, cnt, 0, root);

        cout << maxLevel << endl;
        for(int i = 0; i <= maxLevel; i++){
            ans[i] /= cnt[i];
            cout << cnt[i] << endl;
        }
        return ans;
    }
};