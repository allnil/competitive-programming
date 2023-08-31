#include <ios>
#include<iostream>
#include<vector>

using namespace std;


int main(){
  long long N, X; cin >> N >> X;

  vector<long long> a(N, 0);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  
  long long ans = 0;
  
  if(a[0] > X){
    ans = a[0] - X;
    a[0] = X;
  }

  for(int i = 1; i < N; i++){
    if(a[i] + a[i-1] > X){
     ans+= ((a[i]+a[i-1])-X);
     a[i] -= ((a[i] + a[i-1]) - X);
    }
  }

  cout << ans << endl;
  return 0;
}
