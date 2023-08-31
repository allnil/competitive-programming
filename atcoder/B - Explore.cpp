#include "stdio.h"
#include <cstdio>

const int N = 100050;

long long int A[N];

int main() {
  int n, m, t; scanf("%d %d %d", &n, &m, &t);
  long long int T = t;
  for(int i = 1; i < n; i++){
   int a; scanf("%d",&a);A[i]=-a;
  };
  for(int i = 0; i < m; i++) {
    int x, y; scanf("%d %d", &x, &y);
    A[x]+=y;
  }
  for(int i = 1; i < n; i++){
   T += A[i];
   if (T <= 0) {
     printf("No\n");
     return 0;
   }
  }
  printf("Yes\n");
  return 0;
}
