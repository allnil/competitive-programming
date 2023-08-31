#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;

int main(){
  int n, m; cin >> n >> m;

  vector<vector<int>> g(n, vector<int>());

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<vector<bool>> bit(n, vector<bool>(1 << n));
  vector<vector<int>> dp(1 << n, vector<int>((1 << n), 0));

  dp[1][0] = 1;

  for(int mask = 2; mask < (1 << n) - 1; mask++){
    for(int v = 0; v < n; v++){
      for(auto& u: g[v]){
        if(bit[mask][u]){
          continue;
        } 
        int newmask = mask|(1 << u);
        dp[u][newmask] = dp[v][mask] + 1;
        dp[u][newmask] %= mod;
      }
    }
  }

  cout << dp[n][(1<<n)-1] << endl;
  

  return 0;
}
