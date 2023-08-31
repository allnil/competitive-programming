#include <stdio.h>
#include <cstring>
using namespace std;


int main(){
  long long n; scanf("%lld", &n);
  char c[100];
  sprintf(c, "%lld", n);

  int sumchar = 0;
  for(int i = 0; c[i] != '\0'; i++){
    sumchar += -('0'-int(c[i]));
  }

  if(n % sumchar == 0){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}