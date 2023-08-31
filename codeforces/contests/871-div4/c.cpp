#include <iostream>
#include <vector>
#include <climits>
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
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int minSum = INT_MAX;

    while(n--){
      int minutes; cin >> minutes; 
      string skills; cin >> skills;
      if(skills[0] == skills[1] &&  skills[0] == '1'){
        minSum = min(minSum, minutes);
        min1 = min(min1, minutes);
        min2 = min(min2, minutes);
        continue;
      }
      if(skills[0] == '1') {
        min1 = min(min1, minutes);
      }
      if(skills[1] == '1'){
        min2 = min(min2, minutes);
      }
    }
    if(min1 == INT_MAX || min2 == INT_MAX){
      cout << -1 << endl;
    } else {
      cout << min(minSum, min1 + min2) << endl;
    }
  }
  return 0;
}
