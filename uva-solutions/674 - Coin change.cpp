#include "stdio.h"
#include <cstdio>

int coins[5] = {50,25,10,5,1};
int dp[8192];

int main(){
  int n;
  dp[0] = 1;

  for(int i = 0; i < 5; ++i)
    for(int j = coins[i]; j < 8192; ++j)
      dp[j] += dp[j-coins[i]];

  while(scanf("%d", &n) != EOF ){  
    printf("%d\n",dp[n]);
  }
  return 0;
}

