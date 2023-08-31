#include <iostream>
#include <vector>

using namespace std;
const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();


int main(){
  int t; cin >> t;
  while(t--){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    
  }
  return 0;
}
