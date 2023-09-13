class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int ans = 0;
       int rows = grid.size();
       int cols = grid[0].size();
       for(int i = 0; i < rows; i++){
           for(int j = 0; j < cols; j++){
               if(grid[i][j] == 0){
                   continue;
               }
               int cur = 4;
               cur -= (i - 1 >= 0 ? grid[i-1][j] : 0);
               cur -= (j - 1 >= 0 ? grid[i][j-1] : 0);
               cur -= (i + 1 < rows ? grid[i+1][j] : 0);
               cur -= (j + 1 < cols ? grid[i][j+1] : 0);
               ans += cur;
               cout << cur << endl;
           }
       }
       return ans;
    }
};