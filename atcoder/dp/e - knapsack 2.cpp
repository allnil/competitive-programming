#include "stdio.h"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, W; scanf("%d%d", &N, &W);

  int weights[N+1];

  int values[N+1];
  for(int n = 0; n < N; n++){
    int  w; int v;scanf("%d%d", &w, &v);
    weights[n+1] = w;
    values[n+1] = v;
  }


  int S = 0;
  for(int i = 1; i <= N; i++){
    S += values[i];
  }
  
  const long long INF = 1e18L + 5;
  vector<long long> dp(S+1, INF);

  dp[0]=0;

  for(int i = 1; i <= N; i++){
    for(int j = S - values[i]; j >= 0; j--){
      dp[j + values[i]]=min(dp[j + values[i]], dp[j] + weights[i]);
    }
  }

  long long ans = -1;

  for(int i = 0; i <= S; i++){
    if(dp[i] <= W) {
      ans = max(ans,(long long) i);
    }
  }

  printf("%lld\n", ans);
  return 0;
}
