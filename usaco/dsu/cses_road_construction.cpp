#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct DSU {
 vector<int> e;
 int components;
 int largest_size;
 DSU(int N) {
   largest_size = 1;
   components = N;
   e = vector<int>(N, -1);
 } 


 int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
 int size(int a) { return -e[get(a)]; };
 
 bool same_set(int a, int b) { return get(a) == get(b);}

 bool unite(int x, int y) {
   x = get(x); y = get(y);
   if( x == y ) return false;

   if( e[x] > e[y] ) swap(x, y);
    
   e[x] += e[y];
   e[y] = x;
   largest_size = max(largest_size, -e[x]);
   components--;
   return true;
 }
};


int main(){
  int n, m; cin >> n >> m;
  DSU dsu(n);
  while (m--) {
    int a, b; cin >> a >> b;
    dsu.unite(--a, --b);
    cout << dsu.components << " " <<  dsu.largest_size << endl;
  }
 return 0;
}

