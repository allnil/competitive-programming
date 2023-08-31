#include <iostream>
#include <vector>

using namespace std;
int main(){
  int n; cin >> n;

  vector<string> grid(n);

  for(int i = 0; i < n; i++){
    cin >> grid[i];
  }

  vector<vector<int>> dp(n, vector<int>(n));
  int mod = 1e9 + 7;
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == '*'){
        dp[i][j] = 0;
        continue;
      }
      if(i > 0) dp[i][j] += dp[i-1][j];
      if(j > 0) dp[i][j] += dp[i][j-1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[n-1][n-1] << endl;
  return 0;
}
