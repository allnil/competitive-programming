#include <vector>
#include <iostream>

using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  int n, q; cin >> n >> q;
  
  vector<int> scores(n + 1, 0);

  for(int i = 0; i < q; i++){
    int c, x; cin >> c >>  x;
    if(c == 1){
      scores[x]++;
      continue;
    }
    if(c == 2){
      scores[x] = 2;
      continue;
    }
    if(c == 3){
      if(scores[x] >= 2){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
