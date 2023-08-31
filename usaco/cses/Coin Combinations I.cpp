#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, x; cin >> n >> x;

  vector<int> nums(n);
  for(int i = 0; i < n; ++i){
    cin >> nums[i];
  }

  vector<int> dp(x+10, 0);
  dp[0] = 1;

  const int mod = 1e9 + 7;

  for(int i = 1; i <= x; ++i){
    for(int j = 0; j < n; ++j){
      if(i-nums[j] >= 0){
        (dp[i] += dp[i-nums[j]]) %= mod;
      }
    }
  }

  
  int ans = dp[x] % mod;
  cout << ans << endl;
  return 0;
}

