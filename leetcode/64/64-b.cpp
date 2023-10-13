const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 1; i < grid[0].size(); i++){
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }

        for(int n = 1; n < grid.size(); n++){
            grid[n][0] = grid[n-1][0] + grid[n][0];
        }

        for(int n = 1; n < grid.size(); n++){
            for(int m = 1; m < grid[0].size(); m++){
                grid[n][m] = min(grid[n-1][m] + grid[n][m], grid[n][m-1] + grid[n][m]);
            }
        };
        
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};