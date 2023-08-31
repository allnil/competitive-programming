#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
  private: 
    vector<int> e;
  public:
    DSU(int n){ e = vector<int>(n, -1); }

    int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    bool unite(int x, int y){
      x = get(x); y = get(y);
      if( x == y ) return false;
      
      if(e[x] > e[y]) swap(x, y);

      e[x] += e[y];
      e[y] = x;

      return true;
    }
}
;

struct Wormhole {
  int a;
  int b;
  int w;
};

bool wormhole_compare(const Wormhole& w1, const Wormhole& w2){
  return w1.w < w2.w;
}

int main(){
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  int n,m; cin >> n >> m;  
  
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i]; p[i]--; 
  }
  
  vector<Wormhole> ww(m);
  for(int i = 0; i < m; i++){
    cin >> ww[i].a >> ww[i].b >> ww[i].w;
    ww[i].a--;
    ww[i].b--;
  }

  sort(ww.begin(), ww.end(), wormhole_compare);

  DSU dsu(n);
  
  int wormhole_at = ww.size();
  for(int i = 0; i < n; i++){
    while (!dsu.same_set(i, p[i])) {
      wormhole_at--;
      dsu.unite(ww[wormhole_at].a, ww[wormhole_at].b);
    }
  }

  int ans = wormhole_at == ww.size() ? -1 : ww[wormhole_at].w;
  
  cout << ans << endl;
  return 0;
}

