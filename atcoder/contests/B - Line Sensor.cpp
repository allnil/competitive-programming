#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int h, w; scanf("%d %d", &h, &w);
  
  vector<int> cnt(1000, 0);

  for(int i = 0; i < h; i++){
    for(int j = 0; j <= w; j++){
      char c; scanf("%c", &c);
      if(c == '#'){
        cnt[j] += 1;
      }
    }
  }

  for(int i = 1; i<=w;i++){
    printf("%d ", cnt[i]);
  }
  puts("");
  
}