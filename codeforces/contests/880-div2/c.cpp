#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll getNumMin(ll n){
  switch (n) {
    case 1: 
      return 1;
    case 2:
      return 10;
    case 3:
      return 100;
    case 4: 
      return 1000;
    case 5: 
      return 10000;
    case 6:
      return 100000;
  }
  return -1;
}

ll getNumMax(ll n){
  switch (n) {
    case 1:
      return 9;
    case 2:
      return 99;
    case 3:
      return 999;
    case 4:
      return 9999;
    case 5:
      return 99999;
    case 6:
      return 999999;
  }

  return -1;
}

int main(){
  int t; cin >> t;

  while(t--){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    
    ll x = getNumMin(a);
    ll y = getNumMin(b);
    ll z = getNumMax(c);
    if(x + y > z){
      cout << -1 << endl;
      continue;
    }
    
    ll sol = 0; 
    
    ll minSol = getNumMin(c);
    while(c <= z){

    }
    for(ll i = x; i <= getNumMax(a); i++){
      for(ll j = y; j <= getNumMax(b); j++){
          if(i + j >= getNumMin(c) && i + j <= z){
            sol++;
          } 
          if(sol == k){
            cout << i << " + " << j << " = " << i + j << endl;
            break;
         }
      }
      if(sol == k) break;
    }
  }
  cout << - 1 << endl;

  return 0;
}
