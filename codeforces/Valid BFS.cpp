#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 200007;

vector<int> g[N];
vector<int> idxs(N);	
vector<bool> vis(N);

bool cmp(int a,int b){
	return idxs[a]<idxs[b];
}

int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n - 1; i++){
    int u, v; scanf("%d %d", &u, &v);
    g[u].push_back(v); g[v].push_back(u);
  }

  vector<int> ans;
  vector<int> in(n);

  for(int i = 0; i < n; i++){
    int inn;scanf("%d", &inn);
    in[i] = inn;
		idxs[in[i]]=i;
	}

	for(int i=1;i<=n;i++) {
		sort(g[i].begin(),g[i].end(),cmp);
  }

  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int v = q.front();
    ans.push_back(v);
    q.pop();

    for(int u: g[v]) {
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
      }
    }
  }

 
  if (ans == in){
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
