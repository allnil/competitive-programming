#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

#define N 1000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> g(N);
int vis[105];

bool dfs(int v, int col,int dst){
	vis[v]=1;
	if(v==dst) return 1;
	for(int i = 0; i < g[v].size(); i++){
		ii e=g[v][i];
		if(e.second==col && !vis[e.first]){
			if(dfs(e.first,col,dst)) return true;
		}
	}
	return false;
}

int main(){
  int n, m;scanf("%d %d", &n, &m);

  while(m--){
    int a,b,c; scanf("%d %d %d", &a, &b, &c); a--; b--; c--;
    g[a].push_back({b, c}), g[b].push_back({a, c});
  }

  int q;scanf("%d", &q);
  while(q--){
    int u, v;scanf("%d %d", &u, &v); u--;v--;
    int res = 0;
    for(int i =0; i < 100; i++){
      memset((vis),0,sizeof(vis));
      if(dfs(u,i,v)) ++res;
    }
    printf("%d\n", res);
  }
  
  return 0;
}