#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t; cin >> t;
  const long long INF = 10e9 + 11;
  long long minEven, minOdd;
  while(t--){
    int n; cin >> n;
    
    vector<long long> a(n, 0);

    minEven = INF;
    minOdd = INF;
    bool odd = false;

    for(int i = 0; i < n; i++){
      cin >> a[i];
      if(a[i] % 2 != 0){
        minOdd = min(minOdd, a[i]);
      } else {
        minEven = min(minEven, a[i]);
      }
      if(a[i] == 1){
        odd = true;
      }
    }
    
    if(minOdd == INF || minEven == INF){
      cout << "YES" << endl;
      continue;
    }
    bool beaty = true;
    if(odd){
      for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){ // if even
          long long tryOdd = a[i] - minOdd; 
          if(!(tryOdd >= 1)){
            beaty = false;
            break;
          }
        }
      }
    } else {
      for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
          long long tryEven = a[i] - minOdd;
          if(!(tryEven >= 2)){
            beaty = false;
            break;
          }
        }
      }
    }

    if(beaty){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    };

    
  }
  return 0;
}
