#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;


int main(){
  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++){
    int n, q=0;scanf("%d %d", &n, &q);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }

    vector<int> cnt(2, 0);
    vector<long long> sum(2, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j] % 2]++; // nice 
      sum[a[j] % 2] += a[j];
    }

    for (int j = 0; j < q; j++){
    {
      int t,x; scanf("%d %d", &t, &x);

      int c = cnt[t];
      ll s = sum[t];
      cnt[t] -= c;
      sum[t] -= s;

      cnt[t ^ (x%2)] += c;
      sum[t ^ (x % 2)] += s + (ll) x * c;

      printf("%lld\n", sum[0] + sum[1]);
    }
  }
  }

  return 0;
}