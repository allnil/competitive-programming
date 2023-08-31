#include <cstdio>
#include <stdio.h>
#include <algorithm>

int main(){
  int N, M;
  scanf("%d%d", &N, &M);
  const int NMAX = 50;
  int A[NMAX], B[NMAX], C[NMAX], D[NMAX];

  for(int i=0;i<N;++i){
    scanf("%d%d", &A[i], &B[i]);
  }

  for(int j=0; j<M;++j){
    scanf("%d%d",&C[j], &D[j]);
  }

  for(int i=0; i<N;++i){
    int min_dist=abs(A[i]-C[0])+abs(B[i]-D[0]), checkpoint=1;
    for(int j=1;j<M;++j){
      const int cur_dist=abs(A[i]-C[j])+abs(B[i]-D[j]);
      if(min_dist>cur_dist){
        min_dist=cur_dist;
        checkpoint=j+1;
      }
    }

    printf("%d\n", checkpoint);
  }

  return 0;
}
