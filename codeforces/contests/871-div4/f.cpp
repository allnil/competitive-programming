#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();


int main(){
  int t; cin >> t;

  while(t--){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(m+1, vector<int>(0));
    vector<vector<int>> rg(m+1, vector<int>(0));

    for(int i = 0; i < m; i++){
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      rg[v].push_back(u);
    }

    int borderV = -1; 
    for(int i = 1; i <= m; i++){
      if(g[i].size() == 0){
        borderV = i;
        break;
      }
    }
    cout << borderV << endl;

    int second_l = rg[borderV][0];
    cout << second_l << endl;
    int y = g[second_l].size();
    int central = rg[second_l][0];
    int x = g[central].size();
    cout << x << y << endl; 
    
  }
  return 0;
}
