#include <iostream>
#include <vector>


using namespace std;


int main(){
  int H, W, A, B; 
  cin >> H >> W >> A >> B;

  vector<vector<int>> dp(H, vector<int>(W));
  
  dp[0][0] = 1;
  const long long MOD = 10e9 + 7;
      for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i > 0){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
            if(j > 0){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
        for(int i = H - A; i < H; i++){
        for(int j = 0; j < B; j++){
            if(i > 0){
                dp[i][j] -= dp[i-1][j];
                if(dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
      }
  cout << dp[H-1][W-1] << endl;
  return 0;
}
