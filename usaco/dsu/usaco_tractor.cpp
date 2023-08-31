#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class DSU{
  private:
    vector<int> e;
  public:
    DSU(int n) { e = vector<int>(n*n, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool unite(int x, int y){
      x = get(x); y = get(y);

      if( x == y ) { return false; };

      if(e[x] > e[y]) swap(x, y);

      e[x] += e[y];
      e[y] = x;
      return -e[x] >= (e.size() + 1) / 2;
    }
};


struct Edge {
  int x1; int y1;
  int x2; int y2;
  int w;
};

int main(){
  freopen("tractor.in", "r", stdin);
  freopen("tractor.out", "w", stdout);


  int n; cin >> n;

  vector< vector<int> > grid(n, vector<int>(n));
  vector<Edge> edges; 

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 1; j < n; j++){
      Edge edge;
      edge.y1 = i; edge.x1 = j - 1;
      edge.y2 = i; edge.x2 = j;
      edge.w = abs(grid[i][j - 1] - grid[i][j]);
      edges.push_back(edge);
    }
  }

  for(int i = 0; i < n; i++){
    for (int j = 1; j < n; j++) {
          Edge edge;
          edge.y1 = j - 1; edge.x1 = i;
          edge.y2 = j;
          edge.x2 = i;
          edge.w = abs(grid[j-1][i] - grid[j][i]);
          edges.push_back(edge);
    }
  }

  auto cmp = [](const Edge& e1, const Edge& e2) { return e1.w < e2.w; };

  sort(edges.begin(), edges.end(), cmp);

  DSU dsu(n);
  for(auto& edge : edges){
    if(dsu.unite(edge.y1*n + edge.x1, n * edge.y2 + edge.x2)){
      cout << edge.w << endl;
      return 0;
    }
  }

  return 0;
}

