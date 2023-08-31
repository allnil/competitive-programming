#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> h(200010);
vector<int> dp(200010);
int main(){
  int n;scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &h[i]);
  }

  dp[0] = 0;
  dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);

  for(int i = 3; i <= n; i++){
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
  }

  printf("%d\n", dp[n]);
  return 0;
}