#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
  vector<int> e;

  DSU(int N) {
    e = vector<int>(N, -1);
  }

  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

  int size(int x) { return -e[get(x)]; }

  bool same_set(int x, int y) { return get(x) == get(y); }

  bool unite(int x, int y) {
    x = get(x); y = get(y);
    if( x == y ) return false;
    if(e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

int main(){
  freopen("closing.in", "r",  stdin);
  freopen("closing.out", "w", stdout);
  int n, m;

  cin >> n >> m;

  DSU dsu(n);
  
  vector< vector<int> > g(n);
  for(int i = 0; i < m; i++){
    int u,v;cin>>u>>v;u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> conn(n);
  vector<int> queries(n);

  for(int i = 0; i < n; i++){
    cin >> queries[i];
    queries[i]--;
  }

  reverse(queries.begin(), queries.end());
  
  conn[queries[0]] = 1;
  vector<string> ans = {"YES"};

  int cc = 1;

  for(int i = 1; i < n; i++){
    cc++; int u = queries[i];
    conn[u] = 1;
    for(int v : g[u]) {
      if(conn[v]){
        if (dsu.unite(v, u)) {
          cc--;
        }
      }
    }
    ans.push_back(cc == 1 ? "YES" : "NO");
  }
  reverse(ans.begin(), ans.end());

  for(auto& s: ans){
    cout << s << '\n';
  }


  return 0;
}

