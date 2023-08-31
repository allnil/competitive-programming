#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, A; cin >> N >> A;

  vector<int> nums(N, 0);
  int X = 0;
  for(int i = 0; i < N; i++){
    cin >> nums[i];
    X = max(X, abs(nums[i]));
  }

  vector<vector<int>> dp(2, vector<int>(2*51*51, 0));
  
  dp[0][N * X] = 1;
  

  for(int j = 0; j < N; ++j){
    for(int t = 2 * N * X; t >= 0; --t){
      int prevt = t - nums[j];
      if(0 <= prevt && prevt <= 2*N*X){
        dp[1][t] = dp[0][t] + dp[0][prevt];
      }

      swap(dp[0], dp[1]);
    }
  }

  cout << dp[0][N*X] - 1 << endl;
  return 0;
}
