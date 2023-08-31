#include <cstring>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

#define N 200050
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<int> lala(n);

vector<vi> g(N);
vector<bool> vis(N);
int color[N],tc;

int res = 0;

void dfs(int s,int p,int gp)
{
    stack<int> ss;
    vis[s]=1;

    for(int i=1;i<=tc;i++){
        if(i!=p && i!=gp)
            ss.push(i);

        if(ss.size()==g[s].size())
            break;
    }

    for(int a : g[s]){
        if(!vis[a])
        {
            color[a]=ss.top();ss.pop();
            dfs(a,color[a],color[s]);
        }
    }
}

int main(){
  int n;scanf("%d", &n);
  for(int i=1;i<n;i++){
    int a,b;scanf("%d %d", &a, &b);
    g[a].push_back(b), g[b].push_back(a);
  }

  tc=0;
  int k;
  for(int i=1;i<=n;i++)
  {
      k=g[i].size();
      tc=max(tc,k+1);
  }

  color[1]=1;

  
  dfs(1,1,0);

  printf("%d\n",tc);
  for(int i=1;i<=n;i++)
      printf("%d ",color[i]);
  puts("");
  
  return 0;
}
