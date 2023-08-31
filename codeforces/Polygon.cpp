#include <stdio.h>
#include <iostream>

using namespace std; 

int m[50][50];

int main(){
  int T; cin >> T;
  while(T--){
    int n;cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        char c;
        cin >> c;
        m[i][j] = c - '0';
      }
    }
    
    bool ans = true;
    for(int i = n - 2; i >= 0; --i){
      for(int j = n - 2;j >=0; --j){
        if(m[i][j] && !m[i+1][j] && !m[i][j+1]){
          ans = false;
        } 
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}