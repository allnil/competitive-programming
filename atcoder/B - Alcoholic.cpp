#include "stdio.h"
#include <cstdio>

int main(){
  int n, x;scanf("%d %d", &n, &x);
  int A = 0;
  for (int i = 1; i <= n; i++) {
     int v, p; scanf("%d %d", &v, &p);
     A += v * p;
     
     if (A > x * 100) {
       printf("%d\n",i);
       return 0;
     }
  }
  printf("-1\n");
  return 0;
}
