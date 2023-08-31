#include <iostream>

using namespace std;

int main(){
  int t; int N;
  cin >> t;
  while(t--){
    cin >> N;
    string s; 
    cin >> s;
    
    if (s.size() < 2) {
      cout << s;
      continue;
    }
    int minPos = 0;
    for(int i = 1; i < s.size(); i++){
      if(s[minPos] >= s[i]){
        minPos = i;
      }
    }
    string ans;
    ans += s[minPos]; 
    s.erase(minPos, 1);
    ans += s;
    cout << ans << endl;
  }
  
  return 0;
}
