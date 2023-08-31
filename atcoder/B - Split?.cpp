#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
  string s; cin >> s;
  s = '%' + s;
  if (s[1] == '1') {
      printf("No\n");
  } else {
      bool column[7];
      column[0] = (s[7] == '1');
      column[1] = (s[4] == '1');
      column[2] = (s[2] == '1') or (s[8] == '1');
      column[3] = (s[1] == '1') or (s[5] == '1');
      column[4] = (s[3] == '1') or (s[9] == '1');
      column[5] = (s[6] == '1');
      column[6] = (s[10] == '1');
      for (int i = 0; i < 7; ++i) {
          for (int j = 0; j < i; ++j) {
              if (column[i] and column[j]) {
                  for (int k = j + 1; k < i; ++k) {
                      if (!column[k]) {
                          printf("Yes\n");
                          return 0;
                      }
                  }
              }
          }
      }
      printf("No\n");
  }
  return 0;
}