#include <iostream>
#include <vector>


using namespace std;

int main(){
  string s; cin >> s;

  vector<char> stck;

  for(auto& c: s){
    if(c == 'B'){
      if(stck.size() == 0){
        continue;
      }
      stck.pop_back();
    } else {
      stck.push_back(c);
    }
  }

  for(int i = 0; i < stck.size(); i++){
    cout << stck[i];
  }
  cout << endl;
  return 0;
}
