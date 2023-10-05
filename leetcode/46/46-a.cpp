const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    void generate(const vector<int>& n, vector<vector<int>>& ans, vector<int>& p, vector<bool>& vis, int pos){
        if(p.size() == n.size()){
            ans.push_back(p);
            return;
        }

        for(int i = 0; i < n.size(); i++){
            if(vis[i])continue;

            p.push_back(n[i]);
            vis[i] = true;
            generate(n, ans, p, vis, pos + 1);
            vis[i] = false;
            p.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> cur_ans;
       vector<bool> vis(nums.size(), false);
       generate(nums, ans, cur_ans, vis, 0);
       return ans;
    }
};
