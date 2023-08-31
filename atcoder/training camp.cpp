// n times
// power = 1
// power *i
//10*9+7

#include <stdio.h>

typedef long long ll;

int main(){
  ll ans = 1;
  int n;scanf("%d", &n);
  ll mod=1e9+7;
  for(int i=0;i<n;i++){
      ans=(ans*(i+1))%mod;
  }
  
  printf("%llu\n",ans);
}