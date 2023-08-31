#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, x; cin >> n >> x;

  int mod = 1e9 + 7;

  vector<int>dp(x + 1, 0);
  vector<int>money(n);

  for(int i = 0; i < n; i++){
    cin >> money[i];
  }

  dp[0] = 1;

  for(auto coin: money){  
    for(int i = 1; i <= x; i++){
      if(i - coin >= 0){
        dp[i] += dp[i - coin];
        dp[i] %= mod;
      }
    }
  }


  cout << dp[x] << endl;

  return 0;
}

