#include <iostream>
#include <vector>

using namespace std;


const int MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> comp(n, vector<int>(n, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> comp[i][j];
    }
  }

  vector<int> dp(1 << n, 0);
  
  dp[0] = 1;
  
  for(int mask = 0; mask < (1 << n); mask++){
   int pair_num = __builtin_popcount(mask); 

   for(int w = 0;  w < n; w++){
     if((mask & (1 << w)) || !comp[pair_num][w]) continue;
       dp[mask | (1 << w)] += dp[mask];
       dp[mask | (1 << w)] %= MOD;
   }
  }
  cout << dp[(1 << n) - 1]  << endl;
  return 0;
}
