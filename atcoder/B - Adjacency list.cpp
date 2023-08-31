#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 100050

using namespace std;
vector<int> g[N];

using namespace std;
int main(){
  int n,m;scanf("%d %d", &n,&m);
  for(int i = 0; i < m; i++){
  int a, b;
  scanf("%d %d", &a, &b);
  g[a].push_back(b);
  g[b].push_back(a);
  }
  
  for(int i = 1; i <=n; i++){
    sort(g[i].begin(), g[i].end());
    printf("%lu", g[i].size());
    for(int j : g[i])
      printf(" %d", j);
    printf("\n");
  }
  return 0;
}
