const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 1e9));
        dp[0][0] = grid[0][0];

        for(int i = 1; i < grid[0].size(); i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int n = 1; n < grid.size(); n++){
            dp[n][0] = dp[n-1][0] + grid[n][0];
        }

        for(int n = 1; n < grid.size(); n++){
            for(int m = 1; m < grid[0].size(); m++){
                dp[n][m] = min(dp[n-1][m] + grid[n][m], dp[n][m-1] + grid[n][m]);
            }
        };
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};