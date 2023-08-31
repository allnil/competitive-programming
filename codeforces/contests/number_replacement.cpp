#include <stdio.h>

using namespace std;

char s[100];
int a[100];

int main(){
  int t; scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int n; scanf("%d", &n);

    int v;
    for(int j =0; j< n; j++){
      scanf("%d", &v);
      a[j] = v;
    }
    scanf("%s", s);

    bool ok = true;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (a[j] == a[k] && s[j] != s[k]){
          ok = false;
        }
      }
    }

    if (ok){
      printf("YES\n");
    } else { 
      printf("NO\n");
    }
  }
}