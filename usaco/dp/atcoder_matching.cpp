#include <iostream>
#include <vector>


using namespace std;

const int ZERO = []{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

typedef long long ll;

int main(){
  int n; cin >> n;

  vector<vector<int>> matching(n, vector<int>(n, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> matching[i][j];
    }
  }

  vector<int> dp(1 << n);
 
  const int MOD = 1e9 + 7;
  dp[0] = 1;
  
  for(int mask = 0; mask < (1 << n); mask++){
    int pair_num = __builtin_popcount(mask);
    for(int w = 0; w < n; w++){
      if((mask & (1 << w)) || !matching[pair_num][w]) continue;
      dp[mask | (1 << w)] += dp[mask];
      dp[mask | (1 << w)] %= MOD;
    }
  }


  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
