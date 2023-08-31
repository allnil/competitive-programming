#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int main(){
  freopen("time.in)", "r", stdin);
  freopen("time.out", "w", stdout);

  int n,m,c;
  scanf("%d%d%d", &n, &m, &c);

  vector<int> mc(n);
  vector<vector<int> > g(m);
  
  for(int i = 0; i < m; i++){
    int a,b;scanf("%d%d", &a, &b);
    g[a].push_back(b);
  }


  
  return 0;
}