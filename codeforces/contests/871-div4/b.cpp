#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int maxBlanc = 0;
    int cmp = 0;
    bool cons = false;

    for(int i = 0; i < n; i++){
      if(a[i] == 0){
        if(cons){
          cmp++;
          maxBlanc = max(maxBlanc, cmp);
          continue;
        } else {
          cmp = 1;
          cons = true;
          maxBlanc = max(maxBlanc, cmp);
          continue;
        }
      }
      cons = false;
    }

    cout << maxBlanc << endl;
  }
  return 0;
}
