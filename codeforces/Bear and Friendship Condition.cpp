#include <stdio.h>

#include <vector>

#define N 300010

using namespace std;
vector<int> g[N];
vector<bool> used(N);


void dfs(int a, int & cnt_vertices, int & cnt_edges) {
	if(!used[a]) {
    used[a] = true;
    ++cnt_vertices;
    cnt_edges += g[a].size();
    for(int b : g[a])
      if(!used[b])
        dfs(b, cnt_vertices, cnt_edges);
  }
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  while(m--){
    int x,y;scanf("%d %d", &x, &y);
    g[x].push_back(y); g[y].push_back(x);
  }

	for(int i = 1; i <= n; ++i)
		if(!used[i]) {
			int cnt_vertices = 0, cnt_edges = 0;
			dfs(i, cnt_vertices, cnt_edges);
			if(cnt_edges != (long long) cnt_vertices * (cnt_vertices - 1)) {
				puts("NO");
				return 0;
			}
		}
	puts("YES");

  return 0;
}