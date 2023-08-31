#include <iostream>
#include <vector>

using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

using ll = long long;

const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;

ll dp[1 << MAX_N][MAX_N];

int main(){
  int n, m; cin >> n >> m;
  vector<int> g[MAX_N];

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    g[--v].push_back(--u);
  }

  dp[1][0] = 1;
  for(int mask = 2; mask < (1 << n); mask++){
    if((mask & (1 << 0)) == 0) continue;
    if((mask & (1 << (n - 1))) && mask != ((1 << n) - 1)) continue;
    for(int u = 0; u < n; u++){
      if((mask & (1 << u)) == 0) continue;

      int prev = mask - (1 << u);
      for(int v : g[u]){
        if((mask & (1 << v))){
          dp[mask][u] += dp[prev][v];
          dp[mask][u] %= MOD;
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n - 1] << endl;
  return 0;
}
