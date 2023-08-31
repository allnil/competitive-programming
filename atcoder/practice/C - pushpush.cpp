#include <iostream>
#include <list>

using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
int main(){
  int n; cin >> n;
  
  list<int> nums;
  bool pushToBack = true; 
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(pushToBack){
      nums.push_back(a);
    } else {
      nums.push_front(a);
    }
    pushToBack = !pushToBack;
  }
  if(!pushToBack){
    int first = nums.back();nums.pop_back();
    cout <<first;
    for(list<int>::reverse_iterator i = nums.rbegin(); i != nums.rend();i++){
      cout << " " << *i;
    }
    cout << endl;
    return 0;
  }
  int first = nums.front(); nums.pop_front();
  cout << first;
  for(auto& e: nums){
    cout << " " << e;
  }
  cout << endl;
  return 0;
}
