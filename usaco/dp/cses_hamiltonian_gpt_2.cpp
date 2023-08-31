#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int maxN = 20;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n+1, vector<int>());

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    vector<vector<int>> dp((1 << maxN), vector<int>(n+1, 0));

    dp[1][1] = 1;

    for(int mask = 1; mask < (1 << n); mask++){
        for(int v = 0; v < n; v++){
            if(!(mask & (1 << v))) {
                continue;
            }
            for(auto& u: g[v+1]){
                if((mask & (1 << (u-1))) || u == n && mask != (1 << n) - 1){
                    continue;
                }
                int newmask = mask|(1 << (u-1));
                dp[newmask][u] += dp[mask][v+1];
                dp[newmask][u] %= mod;
            }
        }
    }

    cout << dp[(1 << n)-1][n] << endl;

    return 0;
}

