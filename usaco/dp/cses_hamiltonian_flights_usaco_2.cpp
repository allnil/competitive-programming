#include <iostream>
#include <vector>


using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

using ll = long long;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>());

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; u--; v--;
    g[v].push_back(u);
  }

  vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
  const ll MOD =(ll)1e9 + 7;
  
  dp[1][0] = 1;

  for(int mask = 2; mask < (1 << n); mask++){
    if((mask & (1 << 0)) == 0) continue;

    if((mask & (1 << (n - 1))) && mask != ((1 << n) - 1)) continue;

    for(int u = 0; u < n; u++){
      if((mask & (1 << u)) == 0) continue;

      int maskp = mask - (1 << u);
      for(auto& v : g[u]){
        if((mask & (1 << v))){
          dp[mask][u] += dp[maskp][v];
          dp[mask][u] %= MOD;
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n - 1] << endl;
}


