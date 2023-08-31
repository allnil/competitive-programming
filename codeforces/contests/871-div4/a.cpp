#include <iostream>

using namespace std;

int main(){
  const string codeforces = "codeforces";

  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    int cmp = 0;
    for(int i = 0; i < codeforces.size(); i++){
      if(s[i] != codeforces[i]){
        cmp++;
      }
    }
    cout << cmp << endl;
  }
  return 0;
}
