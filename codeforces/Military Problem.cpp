#include <stdio.h>
#include <vector>
#include <set>
 
#include <algorithm>
 
using namespace std;
#define N 100050
 
using namespace std;
vector<int> g[N];

int current_preorder;
vector<int> preorder(N), max_preorder(N), sorted_by_preorder(N);

 

void dfs(int a) {
  sorted_by_preorder[current_preorder] = a;
  preorder[a] = current_preorder++;
  for (int c : g[a]) {
    dfs(c);
  }
  max_preorder[a] = current_preorder-1;
}
 
 
int main(){
  int n, q; scanf("%d %d", &n, &q);
 
  for(int i = 1; i < n; i++){
    int v;scanf("%d",&v);
    g[--v].push_back(i);
  }
 
  current_preorder = 0;
  dfs(0);

  while(q--){
    int u, k;scanf("%d %d", &u, &k);
    u--;k--;
    k += preorder[u];
    int res = -1;
    if(k <= max_preorder[u]) {
      res = sorted_by_preorder[k] + 1;
    }
    printf("%d\n", res);
  }
  return 0;
}