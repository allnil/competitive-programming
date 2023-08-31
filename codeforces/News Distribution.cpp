#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int N = 500010;

vector<int> g[N];
vector<bool> vis(N);
vector<int> cnts(N);
queue<int> con;

int cnt; 
void dfs(int a) {
	if(!vis[a]) {
    cnt++;
    con.push(a);
    vis[a] = true;
    
    for(int b : g[a]){
      if(!vis[b]) {
        dfs(b);
      }
    }
  }
  cnts[a] = cnt;
}

int main(){
  int n, m, k;
	scanf("%d %d", &n, &m);
	while(m--) {
		int k;scanf("%d", &k);
    if (k == 0){
      continue;
    }
    int v;scanf("%d", &v);
    k--;
    while(k--){
      int u;scanf("%d", &u);
      g[v].push_back(u);
		  g[u].push_back(v);
    }
	}

  for(int i = 1; i <= n; ++i){
    if(!vis[i]){
      cnt = 0;
      dfs(i);
      while(!con.empty()){
        int c = con.front();
        cnts[c] = cnt;
        con.pop();
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", cnts[i]);
  }

  puts("");

  return 0;
}