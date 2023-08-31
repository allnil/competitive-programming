#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  set<int> a;
 
  for(int i = 0; i < m; i++){
    int aa; cin >> aa; a.insert(aa); 
  }
 
  vector<long long>dp(n+1, 0);
  dp[0] = 1;
  
  int mod = 1e9 + 7;

  for(int i = 0; i < n; ++i){
   for(int j=i+1;j<=min(n,i+2);++j){
       if(a.count(j) == 0){
            dp[j] += dp[i];
            dp[j] %= mod;  // To prevent overflow
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}
