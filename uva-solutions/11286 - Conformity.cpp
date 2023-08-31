#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int n, cnt, big;

  while(scanf("%d", &n) && n){
    big=0;
    cnt=0;

    map<vector<int>,int>m;
    while(n--){
      vector<int>v;

      for(int i = 1; i <= 5; i++){
        int d; scanf("%d", &d);
        v.push_back(d);
      }
      
      sort(v.begin(), v.end());
      m[v]++;
    }

    map<vector<int>,int>:: const_iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second>big)
        {
            big=it->second;
        }
    }

    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second==big)
        {
            cnt+=big;
        }
    }

    printf("%d\n", cnt);
  }

  return 0;
}