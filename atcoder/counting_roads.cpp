#include <stdio.h>

#include <vector>
using namespace std;

vector<int> g[100];
bool vis[100];

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  
  for(int i =0; i < m; i++){
    int u, v; scanf("%d %d", &u, &v);
    g[u].push_back(v); g[v].push_back(u);
  }
  for(int i = 1; i <=n; i++){
    printf("%lu\n", g[i].size());
  }
  return 0;
}
