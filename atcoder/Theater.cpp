#include <stdio.h>

using namespace std;

int main(){
  int n; scanf("%d", &n);
  int ans = 0;
  while(n--){
    int l,r;scanf("%d %d", &l, &r);
    ans += r-l+1;
  }
  printf("%d\n", ans);
  return 0;
}