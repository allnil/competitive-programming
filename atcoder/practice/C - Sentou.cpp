#include<iostream>
#include <vector>

using namespace std;

int main(){
  int n, t; 
  cin >> n >> t;
  vector<long long> tt(n, 0);
  for(int i = 0; i < n; i++){
    cin >> tt[i];
  }


  long long ans = t;
  if(tt.size() == 1){
    cout << t << endl;
    return 0;
  } 
  
  for(int i = 1; i < n; i++){
    if(tt[i] - tt[i-1] < t){
      ans += tt[i] - tt[i-1];
    } else {
      ans += t;
    }
  }
  cout << ans << endl;
  return 0;
}
