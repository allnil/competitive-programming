#include<iostream>
#include<vector>

using namespace std;


int main(){
  int n, x; cin >> n >> x;
  vector<int> prices(n + 1), pages(n + 1);

  for(int i = 1; i <= n; i++) cin >> prices[i];
  for(int i = 1; i <= n; i++) cin >> pages[i];

  vector<vector<int>> dp(n+1, vector<int>(x+1, 0));


  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= x; j++){
      dp[i][j] = dp[i-1][j];

      int left = j - prices[i];
      if(left >= 0){
        dp[i][j] = max(dp[i][j], dp[i-1][j - prices[i]] + pages[i]);
      }
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}


