#include <stdio.h>

int main(){
  int a,b,x; scanf("%d %d %d", &a, &b, &x);
  int cnt = 0;
  while(a<=b){
    if(a%x==0){
      cnt++;
    }
    a++;
  }
  printf("%d\n", cnt);
  return 0;
}