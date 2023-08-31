#include <stdio.h>
#include <set>


using namespace std;

int main(){
  int in;
  set<int> s;

  int n1, n2;
  while(scanf("%d %d", &n1, &n2)) {
    int cnt = 0;

    if (n1 == 0 && n2 == 0) {
      break;
    }
    while(n1--){
      scanf("%d",&in);
      if (s.count(in)){
        cnt++;
      } else {
        s.insert(in);
      };
    }
    while(n2--){
      scanf("%d",&in);
      if (s.count(in)){
        cnt++;
      } else {
        s.insert(in);
      };
    }
    printf("%d\n", cnt);
    s.clear();
  }
  return 0;
}