#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class DSU {
  private:
    vector<int> e;
  public:
    DSU(int n){ e = vector<int>(n, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int x, int y){ return get(x) == get(y); }

    int size(int x) { return -e[get(x)]; }
 
    bool unite(int x, int y) {
      x = get(x); y = get(y);

      if(x == y) return false;

      if(e[x] > e[y]) swap(x, y);

      e[x] += e[y];
      e[y] = x;
      return true;
    }
};

struct Edge { int a, b, dist; };

int main(){
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int n; scanf("%d", &n);

  vector<pair<int, int> > xy(n);
  vector<Edge> edges;

  DSU dsu(n);

  for(int i = 0; i < n; i++){
    int x, y; scanf("%d %d", &x, &y);
    xy[i] = pair<int,int>(x,y);  
  }
  

  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      int dx = xy[i].first - xy[j].first;
      int dy = xy[i].second - xy[j].second;
      edges.push_back({i, j, dx * dx + dy*dy});
    }
  }
	auto cmp = [] (const Edge& e1, const Edge& e2) { return e1.dist < e2.dist; };

  sort(edges.begin(), edges.end(), cmp);

  int last_dist = 0;
  int comp_num = n;

  for(const Edge& e : edges) {
    if(dsu.unite(e.a, e.b)){
      last_dist = e.dist;
      if(--comp_num == 1) {
        break;
      }
    }
  }


  printf("%d\n", last_dist);
  return 0;
}


