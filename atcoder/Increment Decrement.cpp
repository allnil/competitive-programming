#include <cstdio>
#include <stdio.h>

char c[110];

int main(){
  int n; scanf("%d", &n);

  scanf("%s", c);
  int res = 0;
  int resMax = 0;
  for(int i = 0; i < n; i++){
    if(c[i] == 'I'){
      res++;
    } else{
      res--;
    }
    if (res > resMax){
      resMax = res;
    }
  }
  printf("%d\n", resMax);
  return 0;
}
