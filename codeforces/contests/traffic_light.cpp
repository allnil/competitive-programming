#include <stdio.h>
#include <cstring>
#include <math.h>
#include <string.h>

using namespace std;



int main(){
  char s[200050];

  int t; scanf("%d", &t);

  const char g = 'g';
  while(t--){
    int sec = 0;
    int n;scanf("%d", &n); 
    char c; scanf("%c", &c);
    scanf("%s", s);

    int minG = 1000000000;
    int maxC = 0;
    for(int i = 0; i < n; i++){
      if(strcmp(&c, &s[i])){
        if(i>maxC){
          maxC=i;
        }
      }
      
      if(strcmp(&s[i], &g)){
        if(i < minG){
          minG=i;
        }       
      } 
    }
    
    sec = minG-maxC + n;

    printf("%d\n", sec);
  }

  return 0;
}