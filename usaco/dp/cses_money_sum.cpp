#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
  int n; cin >> n;

  vector<int> coins(n);
  int totalSum = 0;

  for(int i = 0; i < n; i++){
    cin >> coins[i];
    totalSum += coins[i];
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

  for(int i = 0; i <= n; i++){
    dp[i][0] = true;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= totalSum; j++){
      dp[i][j] = dp[i-1][j];
      if(j - coins[i - 1] >= 0){
        dp[i][j] = dp[i][j] || dp[i - 1][j-coins[i-1]];
      }
    }
  }

  int cnt = 0; 
  for(int i = 1; i <= totalSum; i++){
    if(dp[n][i]){
      cnt++;
    }
  }

  cout << cnt << endl;
  
  bool first = true;
  for(int i = 1; i <= totalSum; i++){
    if(dp[n][i]){
      if(first){
        cout << i;
        first = false;
        continue;
      }
      
      cout << " " << i; 
    }
  }
  cout << endl;

  return 0; 
}


