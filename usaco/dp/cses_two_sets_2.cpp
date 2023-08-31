#include <iostream>
#include <vector>


using namespace std;


int main(){
  int n; cin >> n;

  int totalSum = n*(n+1)/2;
 
  if(totalSum % 2){
    cout << 0 << endl;
    return 0;
  }

  totalSum = totalSum / 2;

  vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

  int mod = 1e9 + 7;

  dp[0][0] = 1;
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= totalSum; j++){
      dp[i][j] = dp[i-1][j];
      if(j - i >= 0){
        dp[i][j] = max(dp[i - 1][j], dp[i][j] + dp[i - 1][j - i]);
        dp[i][j] %= mod;
      }
    }
  }

 cout << dp[n - 1][totalSum] << endl;

  return 0;
}
