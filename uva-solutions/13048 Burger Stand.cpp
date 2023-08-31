#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
int main() {
  char s[100];
 
  
  int n;scanf("%d", &n);
  int f = n;

  while(n--){
      scanf("%s", s);
      int len = strlen(s);

      int result = 0;
      for (int i = 0; i < len; i++) {
        if (s[i] != '-') {
          continue;
        }
        int valid = 1;

        if (i + 1 < len && s[i+1] == 'B') {
          valid = 0;
        } 

        if (i + 2 < len && s[i+2] == 'B') {
          valid = 0;
        }

        if (i + 1 < len && s[i+1] == 'S') {
           valid = 0;
        } 

        if (i - 1 >= 0 && s[i-1] == 'S') {
          valid = 0;          
        }

        if(valid) {
          result++;
        }
      }

      printf("Case %d: %d\n", f - n, result);
  }
  
  return 0;
}