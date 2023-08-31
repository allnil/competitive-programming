#include <iostream>
#include <set>

using namespace std;


int main(){
  int t; cin >> t;
  while(t--){
    set<string> melodies;
    
    int n; cin >> n; string s;
    cin >> s;
    int l = 0;
    int r = 1;
    while(r < n){
      string m = s.substr(l, 2);
      melodies.insert(m);
      l++; r++;
    }
    cout << melodies.size() << endl;
  }
  return 0;
}
