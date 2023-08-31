#include <iostream>
#include <vector>

using namespace std;

int N;

int backtrack(const vector<int>& a){
  for(int x = 0; x < 256; x++){
    int ans = a[0] ^ x;
    for(int i = 1; i < N; i++){
      ans ^= (a[i] ^ x); 
    }
    if(ans == 0){
      return x;
    }
  }

  return -1;
}


int main(){
  int t; cin >> t;
  vector<int> a(1000 + 1, -1);

  while(t--){
    cin >> N;
    
    for(int i = 0; i < N; i++){
      cin >> a[i];
    }

    cout << backtrack(a) << endl;
  }
  return 0;
}



