#include <stdio.h>
#include <cstring>

int main(){
  char s[200];scanf("%s", s);
  int n = strlen(s);
  printf("%.1s%d%s\n", &s[0],n-2,&s[n-1]);
}