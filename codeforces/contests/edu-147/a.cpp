#include <iostream>
#include <vector>
#include <string>
using namespace std;

int quick_pow10(int n)
{
    static int pow10[11] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n];
}

void calcRecurse(const string& s, int pos, int &ans){
  if(s.size() == pos){
    return;
  }

  if(s[pos] == '?'){
    if(s[0] == '?') {
      ans = quick_pow10(pos) - quick_pow10(pos - 1);
    } else {
      ans =  quick_pow10(pos) ;
    }
  }
  
  
  calcRecurse(s, pos + 1, ans);
}



int main(){
  int t; cin >> t;

  string s;

  for(int i = 0; i < t; i++){
    cin >> s;
    if(s == "0" || s[0] == '0'){
      cout << 0 << endl;
      continue;
    }
    if(s.size() == 1 && s[0] != '?'){
      cout << 1 << endl;
      continue;
    }
    
    int ans = 1;
    if(s[0] == '?') ans = 9;
    calcRecurse(s, 0, ans);
    cout << ans << endl;
  }
  return 0;
}

