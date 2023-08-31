#include <iostream>
#include <vector>


using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

const int MN = 52;
int main(){
  int n, a; cin >> n >> a;

  int x[n];

  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  long long dp[MN][MN * MN] = {};
  dp[0][0] = 1;

  for(int i =0; i < n; i++){
    for(int j = n; j >= 0; j--){
      for(int k = x[i]; k < MN * MN; k++){
        dp[j][k] += dp[j-1][k-x[i]];
      }
    }
  }
  long long ans = 0;
  for(int j = 1; j <= n; j++){
    ans += dp[j][a*j];
  }
  cout << ans << endl;
  return 0;
}
