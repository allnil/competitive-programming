#include <iostream>
#include <string_view>


using namespace std;

const string s1 = "dream";
const string s2 = "dreamer";
const string s3 = "erase";
const string s4 = "eraser";

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

bool dfs(string_view S, const string& postfix, int pos){
  if(pos >= S.size()){
    return true;
  }
  if(S.substr(pos, postfix.size()) == postfix){
    // S.erase(0, postfix.size());
    return dfs(S, s1, pos + postfix.size()) || dfs(S, s2, pos + postfix.size()) 
      || dfs(S, s3, pos + postfix.size()) || dfs(S, s4, pos + postfix.size());
  }

  return false;
}

int main(){
  string S; cin >> S;
  if(dfs(S, "", 0)){
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
   

  return 0;
}
