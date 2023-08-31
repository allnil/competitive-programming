#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int dfs(const vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis){
  if(col < 0 || row < 0){
    return 0;
  }
  if(grid.size() <= row){
    return 0;
  }
  if(grid[0].size() <= col){
    return 0;
  }
  if(vis[row][col]){
    return 0;
  }
  if(grid[row][col] == 0){
    return 0;
  }
  vis[row][col] = true;
  
  return dfs(grid, row, col + 1, vis)  + dfs(grid, row, col - 1, vis)
    + dfs(grid, row + 1, col, vis) + dfs(grid, row - 1, col, vis) + grid[row][col];
}

int main(){
  int t; cin >> t;

  while(t--){
    int n, m; cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> grid[i][j];
      }
    }

    int ans = -1e9;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        int lake = dfs(grid, i, j, vis);
        ans = max(ans, lake);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
