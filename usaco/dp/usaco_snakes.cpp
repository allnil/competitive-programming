#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int ZERO = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

void print(const vector<vector<int>>& dp, int g, int N, int K){
  cout  << "net size" << " " <<  g << "\n";
   for(int i = 0; i <= N; i++){
    for(int j = 0; j <= K; j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  

  int N, K; cin >> N >> K;

  vector<int> groups(N + 1);

  for(int i = 1; i <= N; i++){
    cin >> groups[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(K +1, 0));

  int spaceUsed = 0;
  int maxGroup = 0;
 
  for(int i = 1; i <= N; i++){
    maxGroup = max(maxGroup, groups[i]);
    
    dp[i][0] = maxGroup * i;

    for(int j = 1; j <= K; j++){
      dp[i][j] = INT_MAX - 1;
      int netSize = groups[i];

      for(int c = i - 1; c >= 0; c--){
        dp[i][j] = min(dp[i][j], dp[c][j-1] + netSize*(i - c));
        netSize = max(netSize, groups[c]); 
//        print(dp, netSize, N, K);
      }
    }
    spaceUsed += groups[i];
  }
   

  cout << dp[N][K] - spaceUsed << "\n";
  

  return 0;
}

