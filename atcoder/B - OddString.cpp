#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
  char s[100050];scanf("%s",s);
  int i = 0;
  while(s[i] != '\0'){
    if(!(i&1)){
      printf("%c",s[i]);
    }
    i++;
  }
  printf("\n");
  return 0;
}