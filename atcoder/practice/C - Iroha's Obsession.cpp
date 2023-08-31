#include <iostream>
#include <vector>
using namespace std;


bool good(const vector<bool>& bad, int N){
  while(N > 0){
    int x = N % 10;
    if(bad[x]) return false;
    N /= 10;
  }
  return true;
}

int main(){
  int N, K; cin >> N >> K;

  vector<bool> bad(10, false);

  for(int i = 0; i < K; i++){
    int x; cin >> x;
    bad[x] = 1;
  }

  while(!good(bad, N)) N++;

  cout << N << endl;

  
  return 0;
}
