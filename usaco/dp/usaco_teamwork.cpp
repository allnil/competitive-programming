#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ZERO = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  freopen(string("teamwork.in").c_str(), "r", stdin);
  freopen(string("teamwork.out").c_str(), "w", stdout);

  int N, K;

  cin >> N >> K;

  vector<int> skills(N);

  for(int i = 0; i < N; i++){
    cin >> skills[i];
  }

  vector<int> dp(N + 1, 0);

  for(int i = 1; i <= N; i++){
    int max_skill = 0;
    for(int j = 1; j <= K; j++){
      if(i - j < 0){
        break;
      }

      max_skill = max(max_skill, skills[i-j]);
      dp[i] = max(dp[i], dp[i-j] + max_skill * j);
    }
  }

  cout << dp[N] << endl;
  return 0;
}

