#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define N 300010

using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;

int n,m;
typedef vector<int> vi;
bool used[N];
vector<vi> g(N);
vector<int> seq;


int main(){
  scanf("%d %d", &n, &m);

  while(m--){
    int x,y; scanf("%d %d", &x, &y);
    g[x].push_back(y), g[y].push_back(x);
  }
  
  used[1] = true;
  Q.push(1);

  while(!Q.empty()){
    int now = Q.top();
    Q.pop();
    seq.push_back(now);

    for(auto p: g[now]){
      if(!used[p]){
        Q.push(p);
        used[p] = true;
      }
    }
  }


	for (auto p : seq){
		printf("%d ", p);
	}
	puts("");
	return 0;
}