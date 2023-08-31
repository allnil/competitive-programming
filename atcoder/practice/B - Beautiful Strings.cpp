#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
  string w; cin >> w;
  unordered_map<char, int> cnt;

  for(auto& c: w){
    cnt[c]++;
  }

  bool nice = true;
  for(auto& a: cnt){
    if(a.second % 2 == 0){
      continue;
    }
    nice = false;
    break;
  }
  if(nice){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
