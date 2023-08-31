#include <stdio.h>
#include <vector>

using namespace std;

#define N 10040

vector<int> g[N];
vector<bool> used(N);


void dfs(int a) {
	if(!used[a]) {
    used[a] = true;
    
    for(int b : g[a])
      if(!used[b])
        dfs(b);
  }
}

int main(){
  int n;scanf("%d",&n);

  for(int i = 1; i <= n; i++){
    int u;scanf("%d",&u);
    g[i].push_back(u); g[u].push_back(i);
  }

  int cnt = 0;

  for(int i = 1; i <= n; ++i){
		if(!used[i]){
      dfs(i);
      cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}


/* tourist

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  set <int> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int foo;
    scanf("%d", &foo);
    if (foo == i) {
      ans++;
    } else {
      s.insert(foo);
    }
  }
  printf("%d\n", ans + (int) s.size() / 2);
  return 0;
}
*/