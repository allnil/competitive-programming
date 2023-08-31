#include <stdio.h>

int main(){
  long long  int a,b,c;scanf("%d %d %d", &a, &b,&c); 
  long long int j = 0;

  for(int i = a; i <= b; i++){
    if(i%c==0){
      j++;
    }};
  printf("%lld\n",j);
  return 0;
}
