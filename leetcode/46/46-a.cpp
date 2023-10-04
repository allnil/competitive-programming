const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    vector<bool> vis;

    void backtrack(int cur_i, vector<int>& nums) {
        if(p.size() == nums.size()){
            ans.push_back(p);
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;
            if(p.size() <= nums.size()){
                p.push_back(nums[i]);
                vis[i] = true;
                backtrack(cur_i + 1, nums);
                vis[i] = false;
                p.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        backtrack(0, nums);
        return ans;
    }
};