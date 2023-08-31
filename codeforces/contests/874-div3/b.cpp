#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    vector<long long> a(n, 0);
    vector<long long> b(n, 0);
    vector<bool> vis(n, false);
    vector<long long> out(n, 0);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    for(int i = 0; i < n; i++){
      cin >> b[i];
    }
    
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        vector<long long>::iterator lower, upper;
        lower = lower_bound(b.begin(), b.end(), a[i]);
        upper = upper_bound(b.begin(), b.end(), a[i]);
        
    }
    

  }
  return 0;
}
