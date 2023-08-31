#include <iostream>
#include<vector>

using namespace std;


const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int ans = 0;
int T = 0;
void dfs(const vector<vector<int>>& g, vector<int>& up, vector<int>& tin, vector<bool>& mark,
    int v, int p){
  up[v]=tin[v]= T++;
  mark[v] = true;
  for(auto u: g[v]){
    if(u == p){
      continue;
    }
    if(mark[u]){
      up[v] = min(up[v], tin[u]);
    } else {
      dfs(g,up, tin, mark, u, v);
      up[v] = min(up[v], up[u]);
    }
  }
  if(up[v] > tin[p]){
    ans++;
  }
}

int main(){
  int N, M; cin >> N >> M;

  vector<vector<int>> g(N+1, vector<int>(0));
  vector<int> up(N+1, 0);
  vector<int> tin(N+1, 0);
  vector<bool> mark(N+1,0);
  
  for(int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(g, up, tin, mark, 1, 1);
  cout << ans << endl;
  return 0;
}
