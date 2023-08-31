#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n+1,0);
  vector<int> b(n);
  for(int i = 0; i < n + 1; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    long long t = min(a[i], b[i]);
    ans += t;
    a[i] -= t;
    b[i] -= t;

    t = min(a[i+1], b[i]);
    ans += t;
    a[i+1] -= t;
    b[i] -= t;
 }
  
  cout << ans << endl;

  return 0;
}
