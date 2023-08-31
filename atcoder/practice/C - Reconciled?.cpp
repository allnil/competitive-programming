#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9+7;


int main(){
  int n, m; cin >> n >> m;
  
  if(abs(n - m) > 1){
    cout << 0 << endl;
    return 0;
  }
  long long dogs = 1;
  for(long long i = 2; i <= n; i++){
    dogs = i * dogs;
    dogs %= mod; 
  }
  long long monkeys = 1;
  for(long long i = 2; i <= m; i++){
      monkeys = i * monkeys;
      monkeys %= mod;
  }
  if(n == m){
    cout << 2 * monkeys * dogs % mod << endl;
  } else {
    cout << monkeys * dogs  % mod << endl;
  }
  
  return 0;
}
