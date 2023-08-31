#include <stdio.h>

#include <vector>
#include <queue>

const int N = 200050;

using namespace std;

vector<int> g[N];

vector<int> vals(N, 0);
vector<bool> used(N);
vector<int> p(N);
vector<int> d(N);

void go(int s, int to){
  queue<int> q;
  q.push(s);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i=0; i<g[v].size(); ++i) {
      int to = g[v][i];
      if (!used[to]) {
        used[to] = true;
        q.push(to);
        d[to] = d[v] + 1;
        p[to] = v;
      }
    }
  }
  vector<int> path;
  for (int i=v; i!=-1; i=p[v])
    path.push_back(v);
  reverse (path.begin(), path.end());
  
  for (size_t i=0; i<path.size(); ++i)
    
}

int main(){
  int n; scanf("%d", &n);

  for(int i = 1; i < n; i++){
    int u,v; scanf("%d %d", &u, &v);
    g[u].push_back(v);g[v].push_back(u);
  }

  int m; scanf("%d", &m);

  for(int i = 0; i < m; i++){
    int q;(scanf("%d", &q));
    if(q == 1){
      int v; scanf("%d", &v);

      printf("%d", vals[v]);
    }
    if(q == 2){
      int u,v,k,d; scanf("%d %d %d %d", &u,&v,&k,&d);
      used.clear();
      go(u,v);
    }
  }
  return 0;
}