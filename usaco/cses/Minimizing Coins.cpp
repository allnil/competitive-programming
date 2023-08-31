#include <cstdio>
#include <iostream>

#include <vector>

using namespace std;
int main(){
  int n,x; 
  cin >> n >> x;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }

  vector<int> dp(x+10, 1e9);

  dp[0] = 0;

  for(int i = 1; i <= x; i++){
    for(int j = 0; j < n; j++){
      if(i - nums[j] >= 0) {
        dp[i] = min(dp[i], dp[i-nums[j]] + 1);
      }
    }
  }
  if(dp[x] == 1e9) {
    cout << -1 << endl;
  } else { 
    cout << dp[x] << endl;
  }

  return 0;
}

