#include <iostream>
#include <vector>

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
    vector<int> cnt(100 + 1, 0);

    for(int i = 0; i < n; i++){
      int num; cin >> num;
      cnt[num]++;
    }
    
    bool check = true;
    for(int i = 1; i < 101; i++){
      if(cnt[i] > cnt[i-1]){
        check = false;
        break;
      } 
    }
    if(check){
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
