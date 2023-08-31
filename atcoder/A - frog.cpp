#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

// N stones, 1<=i<=N
// Hi - height of Stone i
// frog initially on Stone 1
// He will try to reach stone N
// repeate: 
//  jump to stone i + 1 or i + 2, cost is Hi - Hj, where j is the stone to land on
// find the MINIMUM possible total cost incurred before the frog reaches STone N
const int N = 100050;

int dp[N];
int in[N];

int main(){
  int n; scanf("%d", &n); 
  int step = 2;
  for(int i = 1; i <= n; i++){
    int h; scanf("%d", &h);
    in[i]=h;
  }
  for(int i = 3; i <= n; i++){
    int h1 = std::abs(in[i-1]-in[i]);
    int h2 = std::abs(in[i-2]-in[i]);
    int minh = std::min(h1, h2);
    dp[i]=minh;
  } 
  printf("%d\n", dp[n]);

  return 0;
}
